typedef std::array<int, 2> pair;
const int MOD = 1e9 + 7;

pair operator*(const pair& lhs, const pair& rhs) { return {int((1LL * lhs[0] * rhs[0]) % MOD), int((1LL * lhs[1] * rhs[1]) % MOD)}; }
pair operator+(const pair& lhs, const pair& rhs) { return {(lhs[0] + rhs[0]) % MOD, (lhs[1] + rhs[1]) % MOD}; }
pair operator-(const pair& lhs, const pair& rhs) { return {((lhs[0] - rhs[0]) % MOD + MOD) % MOD, ((lhs[1] - rhs[1]) % MOD + MOD) % MOD}; }
pair operator*(const pair& lhs, const int rhs) { return lhs * pair{rhs, rhs}; }
pair operator+(const pair& lhs, const int rhs) { return lhs + pair{rhs, rhs}; }
pair operator-(const pair& lhs, const int rhs) { return lhs - pair{rhs, rhs}; }

class rollingHash {
   public:
    const pair base = {53, 59};
    std::vector<pair> pow, pref;
    rollingHash(const std::string& s) {
        int n = (int)s.size();
        pow.resize(n + 1);
        pref.resize(n + 1);
        pow[0] = {1, 1};
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] * base + (s[i] - 'a');
            pow[i + 1] = pow[i] * base;
        }
    }
    pair query(int l, int r) {
        return pref[r] - pref[l] * pow[r - l];
    }
};
