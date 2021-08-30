
#include "bits/stdc++.h"
using namespace std;
using i64 = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	string vowel = "AEIOU";
	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		string s;
		cin >> s;
		map<char, int> cnt;
		int n = (int)s.size(), sumco = 0, sumvo = 0;
		for (int i = 0; i < n; ++i) {
			if (vowel.find(s[i]) == string::npos) {
				sumco++;
			} else {
				sumvo++;
			}
			cnt[s[i]]++;
		}
		int mxco = 0, mxvo = 0;
		for (auto& it : cnt) {
			if (vowel.find(it.first) == string::npos)
				mxco = max(mxco, it.second);
			else
				mxvo = max(mxvo, it.second);
		}
		int ans = 10000;
		if (sumco)
			ans = min(ans, sumco - mxco + n - mxco);
		else
			ans = min(ans, n);
		if (sumvo)
			ans = min(ans, sumvo - mxvo + n - mxvo);
		else
			ans = min(ans, n);
		cout << ans << '\n';
	}
}
