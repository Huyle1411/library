template <typename T>
vector<int> kmp_table(const T& pattern, int n)
{
	vector<int> pi(n);
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			++j;
		pi[i] = j;
	}
	return pi;
}
template <typename T>
vector<int> kmp_table(const T& pattern)
{
	return kmp_table(pattern, (int)pattern.size());
}
template <typename T>
vector<int> kmp_search(const T& pattern, int n, const T& text, int m, const vector<int>& pi)
{
	assert(n > 0 && (int)pi.size() == n);
	vector<int> occurences;
	int j = 0;
	for (int i = 0; i < m; ++i) {
		while (j > 0 && (j == n || text[i] != pattern[j]))
			j = pi[j - 1];
		if (text[i] == pattern[j])
			++j;
		if (j == n)
			occurences.push_back(i - n + 1); //0-indexed position
	}
	return occurences;
}
template <typename T>
vector<int> kmp_search(const T& pattern, const T& text, const vector<int>& pi)
{
	return kmp_search(pattern, (int)pattern.size(), text, (int)text.size(), pi);
}
