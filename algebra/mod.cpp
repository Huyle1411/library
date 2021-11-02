template <class T>
T binpow(T a, int64_t b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

template <int _MOD>
struct modnum {
  static constexpr int P = _MOD;

 private:
  int x;

 public:
  // assume -P <= x < 2P
  int normalize(int _x) {
    if (_x < 0) {
      _x += P;
    }
    if (_x >= P) {
      _x -= P;
    }
    return _x;
  }
  modnum(int _x = 0) : x(normalize(_x)) {
  }
  int val() const { return x; }
  modnum operator-() const { return modnum(normalize(P - x)); }
  modnum inv() const {
    assert(x != 0);
    return binpow(*this, P - 2);
  }
  modnum& operator*=(const modnum& rhs) {
    x = (int)(int64_t(x) * rhs.x % P);  // avoid warning, assume P has type int
    return *this;
  }
  modnum& operator+=(const modnum& rhs) {
    x = normalize(x + rhs.x);
    return *this;
  }
  modnum& operator-=(const modnum& rhs) {
    x = normalize(x - rhs.x);
    return *this;
  }
  modnum& operator/=(const modnum& rhs) {
    return *this *= rhs.inv();
  }
  friend modnum operator*(const modnum& lhs, const modnum& rhs) {
    modnum res = lhs;
    res *= rhs;
    return res;
  }
  friend modnum operator+(const modnum& lhs, const modnum& rhs) {
    modnum res = lhs;
    res += rhs;
    return res;
  }
  friend modnum operator-(const modnum& lhs, const modnum& rhs) {
    modnum res = lhs;
    res -= rhs;
    return res;
  }
  friend modnum operator/(const modnum& lhs, const modnum& rhs) {
    modnum res = lhs;
    res /= rhs;
    return res;
  }
};
