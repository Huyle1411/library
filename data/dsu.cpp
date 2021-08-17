class dsu {
   public:
    vector<int> p, sz;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        sz = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int union_find(int x) {
        return (x == p[x] ? x : (p[x] = union_find(p[x])));
    }
    bool union_set(int x, int y) {
        x = union_find(x);
        y = union_find(y);
        if (x != y) {
            if (sz[x] > sz[y])
                swap(x, y);
            p[x] = y;
            sz[y] += sz[x];
            return true;
        }
        return false;
    }
};
