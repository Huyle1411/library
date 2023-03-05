const int p = 29;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 1;  // to calculate max pow
std::vector<i64> computePow(int base, int max_pow, int mod) {
    std::vector<i64> res(max_pow);
    res[0] = 1;
    for (int i = 1; i < max_pow; ++i)
        res[i] = (res[i - 1] * base) % mod;
    return res;
}
std::vector<int> rabin_karp(std::string const& text, std::string const& pattern, std::vector<i64>& p_pow) {
    std::vector<i64> hash_text(text.size() + 1, 0);
    for (int i = 0; i < (int)text.size(); ++i)
        hash_text[i + 1] = (hash_text[i] + (text[i] - 'a' + 1) * p_pow[i]) % MOD;
    i64 hash_pattern = 0;
    for (int i = 0; i < (int)pattern.size(); ++i)
        hash_pattern = (hash_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % MOD;
    std::vector<int> res;
    for (int i = 0; i + pattern.size() - 1 < text.size(); ++i) {
        i64 cur_hash = (hash_text[i + pattern.size()] - hash_text[i] + MOD) % MOD;
        if (cur_hash == hash_pattern * p_pow[i] % MOD)
            res.push_back(i);
    }
    return res;
}
