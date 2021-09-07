template <typename T>
struct sparse_table {
  std::vector<std::vector<T>> ST;
  sparse_table(std::vector<T>& A) {
    int N = A.size();
    int LOG = 32 - __builtin_clz(N);
    ST = std::vector<std::vector<int>>(LOG, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
      ST[0][i] = A[i];
    }
    for (int i = 0; i < LOG - 1; i++) {
      for (int j = 0; j < N - (1 << i); j++) {
        ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
      }
    }
  }
  // range: [L, R) L <= x < R
  int range_min(int L, int R) {
    if (L == R) {
      return INF;
    }
    int d = 31 - __builtin_clz(R - L);
    return min(ST[d][L], ST[d][R - (1 << d)]);
  }
};
