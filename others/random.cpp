using u64 = unsigned long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
i64 myRand(i64 B) {
  return (u64)rng() % B;
}
