template <typename T>
class fenwick {
 public:
  //one-based indexing
  //use for range update and range queries sum
  std::vector<T> fenw1, fenw2;
  int n;
  fenwick(int _n) : n(_n) {
    fenw1.resize(n + 1);
    fenw2.resize(n + 1);
  }

  void add(std::vector<T> &f, int x, T v) {
    while (x <= n) {
      f[x] += v;
      x += x & (-x);
    }
  }

  void range_add(int l, int r, T v) {
    add(fenw1, l, v);
    add(fenw1, r + 1, -v);
    add(fenw2, l, v * (l - 1));
    add(fenw2, r + 1, -v * r);
  }

  T sum(std::vector<T> &f, int x) {
    T v{};
    while (x > 0) {
      v += f[x];
      x -= x & (-x);
    }
    return v;
  }

  T prefix_sum(int x) {
    return sum(fenw1, x) * x - sum(fenw2, x);
  }

  T range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};
