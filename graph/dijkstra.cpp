template <typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& adj, int start, vector<int>& p)
{
	assert(0 <= start && start < (int)adj.size());
	vector<T> dis(adj.size(), numeric_limits<T>::max());
	p = vector<int>(adj.size(), -1);
	dis[start] = 0;
	set<pair<T, int>> q;
	q.emplace(dis[start], start);
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (auto nei : adj[v]) {
			int to = nei.first;
			T len = nei.second;
			if (dis[v] + len < dis[to]) {
				q.erase({ dis[to], to });
				dis[to] = dis[v] + len;
				p[to] = v;
				q.insert({ dis[to], to });
			}
		}
	}
	return dis;
	// return numeric_limits<T>::max() if no path
}
