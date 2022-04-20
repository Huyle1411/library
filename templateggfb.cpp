#include <bits/stdc++.h>

#ifdef DEBUG
#include "debug/debug.h"
#else
#define debug(...) 69
#endif

#define runcase ^-^

void solve(int test_case = 0) {
  std::cout << "Case #" << tc + 1 << ": ";
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0); 
  std::cin.exceptions(std::cin.failbit);
  int T = 1;
#ifdef runcase
  std::cin >> T;
#endif
  for (int tc = 0; tc < T; ++tc) {
    solve(tc);
  }
}
