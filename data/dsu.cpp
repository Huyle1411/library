class dsu {
   public:
    std::vector<int> p, sz;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        sz = std::vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int leader(int x) { return (x == p[x] ? x : (p[x] = leader(p[x]))); }
    bool same(int x, int y) { return (leader(x) == leader(y)); }
    bool join(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x != y) {
            if (sz[x] > sz[y])
                std::swap(x, y);
            p[x] = y;
            sz[y] += sz[x];
            return true;
        }
        return false;
    }
};
