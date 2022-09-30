i64 binpow(i64 base, i64 expon) {
  i64 res = 1;
  while (expon > 0) {
    if (expon & 1)
      res *= base;
    base *= base;
    expon >>= 1;
  }
  return res;
}

i64 binpow(i64 base, i64 expon, i64 mod) {
  base %= mod;
  i64 res = 1;
  while (expon > 0) {
    if (expon & 1)
      res = res * base % mod;
    base = base * base % mod;
    expon >>= 1;
  }
  return res;
}
