#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    ll n, x;
    cin >> n >> x;
    if ((n == 0) && (x == 0)) {
      break;
    }

    ll ans = 0;
    for(ll a = 1; a <= n; a++) {
      for (ll b = (a + 1); b <= n; b++) {
        for (ll c = (b + 1); c <= n; c++) {
          if (a + b + c == x) {
            ans += 1;
          }
        }
      }
    }

    cout << ans << "\n";
  }
  return 0;
}

