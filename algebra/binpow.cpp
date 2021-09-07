template <typename T>
T binpow(T base, T expon) {
  T res = 1;
  while (expon > 0) {
    if (expon & 1)
      res *= base;
    base *= base;
    expon >>= 1;
  }
  return res;
}

template <typename T>
T binpow(T base, T expon, T mod) {
  base %= mod;
  T res = 1;
  while (expon > 0) {
    if (expon & 1)
      res = res * base % mod;
    base = base * base % mod;
    expon >>= 1;
  }
  return res;
}
