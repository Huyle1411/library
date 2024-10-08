template <typename T>
class fenwick {
   public:
    std::vector<T> fenw;
    int n;
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    void add(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
struct node {
    int a = ...;  // don't forget to set default value
    inline void operator+=(node& other) {
        ...
    }
};
