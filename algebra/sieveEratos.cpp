const int N = 10000000;
int leastFac[N + 1];
int mobius[N+1];
vector<int> prime;

void sieve() {
    mobius[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (leastFac[i] == 0) {
            leastFac[i] = i;
            prime.push_back(i);
            mobius[i] = -1;
        }
        for (int j = 0; j < (int)prime.size() && prime[j] <= leastFac[i] && i * prime[j] <= N; ++j) {
            leastFac[i * prime[j]] = prime[j];
            mobius[i * prime[j]] = leastFac[i] == prime[j] ? 0 : -mobius[i];
        }
    }
}
