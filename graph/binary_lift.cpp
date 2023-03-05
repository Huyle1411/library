class binary_lift {
   public:
    std::vector<std::vector<int>> adj;
    int timer;
    std::vector<int> tin, tout;
    std::vector<std::vector<int>> up;
    int n, l;

    binary_lift(int _n) : n(_n) { adj.resize(n); }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    // need to run preprocess before use
    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        // start with 0-index
        timer = -1;
        l = (int)std::ceil(std::log2(n));
        up.assign(n, std::vector<int>(l + 1));
        dfs(root, root);
    }
};
