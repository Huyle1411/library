constexpr int P = 1e9 + 7;
// assume -P <= x < 2P
int normalize(int x)
{
	if (x < 0) {
		x += P;
	}
	if (x >= P) {
		x -= P;
	}
	return x;
}
template <class T>
T binpow(T a, int b)
{
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
struct modnum {
	int x;
	modnum(int _x = 0)
		: x(normalize(_x))
	{
	}
	int val() const
	{
		return x;
	}
	modnum operator-() const
	{
		return modnum(normalize(P - x));
	}
	modnum inv() const
	{
		assert(x != 0);
		return binpow(*this, P - 2);
	}
	modnum& operator*=(const modnum& rhs)
	{
		x = (int)(i64(x) * rhs.x % P); // avoid warning, assume P has type int
		return *this;
	}
	modnum& operator+=(const modnum& rhs)
	{
		x = normalize(x + rhs.x);
		return *this;
	}
	modnum& operator-=(const modnum& rhs)
	{
		x = normalize(x - rhs.x);
		return *this;
	}
	modnum& operator/=(const modnum& rhs)
	{
		return *this *= rhs.inv();
	}
	friend modnum operator*(const modnum& lhs, const modnum& rhs)
	{
		modnum res = lhs;
		res *= rhs;
		return res;
	}
	friend modnum operator+(const modnum& lhs, const modnum& rhs)
	{
		modnum res = lhs;
		res += rhs;
		return res;
	}
	friend modnum operator-(const modnum& lhs, const modnum& rhs)
	{
		modnum res = lhs;
		res -= rhs;
		return res;
	}
	friend modnum operator/(const modnum& lhs, const modnum& rhs)
	{
		modnum res = lhs;
		res /= rhs;
		return res;
	}
};
