template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>>& adj, int start, std::vector<int>& p) {
    assert(0 <= start && start < (int)adj.size());
    std::vector<T> dis(adj.size(), std::numeric_limits<T>::max());
    p = std::vector<int>(adj.size(), -1);
    dis[start] = 0;
    std::set<std::pair<T, int>> q;
    q.emplace(dis[start], start);
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto nei : adj[v]) {
            int to = nei.first;
            T len = nei.second;
            if (dis[v] + len < dis[to]) {
                q.erase({dis[to], to});
                dis[to] = dis[v] + len;
                p[to] = v;
                q.insert({dis[to], to});
            }
        }
    }
    return dis;
    // return numeric_limits<T>::max() if no path
}
