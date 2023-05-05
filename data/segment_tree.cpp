class segment_tree {
   public:
    class node {
       public:
        long long val;
        // Remember init variable (constructor, init func)
        node() : val(0) {}
        void init(long long _val) {
            val = _val;
            ...
        }
        void compute(int l, int r, ... ) {

        }
    };
    int n;
    std::vector<node> tree;
    segment_tree(int _n) : n(_n) {
        tree.resize(n * 2 - 1);
    }
    template <typename H>
    segment_tree(std::vector<H> &a) {
        n = (int)a.size();
        tree.resize(n * 2 - 1);
        build(0, 0, n - 1, a);
    }
    node combine(const node &x, const node &y) {
        node res;
        ...
        return res;
    }
    void push(int v, int tl, int tr) {
        int tm = (tl + tr) >> 1;
        int x = v + 1, y = v + ((tm - tl + 1) << 1);
        // init lazy variable after push
        ...
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) return;
        int tm = (tl + tr) >> 1;
        int x = v + 1, y = v + ((tm - tl + 1) << 1);
        build(x, tl, tm);
        build(y, tm + 1, tr);
        tree[v] = combine(tree[x], tree[y]);
    }
    template <typename H>
    void build(int v, int tl, int tr, std::vector<H> &a) {
        if (tl == tr)
            tree[v].init(a[tl]);
        else {
            int tm = (tl + tr) >> 1;
            int x = v + 1, y = v + ((tm - tl + 1) << 1);
            build(x, tl, tm, a);
            build(y, tm + 1, tr, a);
            tree[v] = combine(tree[x], tree[y]);
        }
    }
    node query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) >> 1;
        int x = v + 1, y = v + ((tm - tl + 1) << 1);
        push(v, tl, tr);
        node res;
        if (tm >= r)
            res = query(x, tl, tm, l, r);
        else if (tm < l)
            res = query(y, tm + 1, tr, l, r);
        else
            res = combine(query(x, tl, tm, l, r), query(y, tm + 1, tr, l, r));
        tree[v] = combine(tree[x], tree[y]);
        return res;
    }
    node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    node query(int pos) {
        return query(pos, pos);
    }
    template <typename... Args>
    void update(int v, int tl, int tr, int l, int r, const Args &...args) {
        if (l <= tl && tr <= r) {
            tree[v].compute(tl, tr, args...);
            return;
        }
        int tm = (tl + tr) >> 1;
        int x = v + 1, y = v + ((tm - tl + 1) << 1);
        push(v, tl, tr);
        if (tm >= l) update(x, tl, tm, l, r, args...);
        if (tm < r) update(y, tm + 1, tr, l, r, args...);
        tree[v] = combine(tree[x], tree[y]);
    }
    template <typename... Args>
    void update(int l, int r, const Args &...args) {
        return update(0, 0, n - 1, l, r, args...);
    }
};
