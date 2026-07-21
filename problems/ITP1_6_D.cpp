#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<ll> b(m);
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }

  for(int i = 0; i < n; i++) {
    ll ans = 0;
    for(int j = 0; j < m; j++) {
      ans += a[i][j] * b[j];
    }

    cout << ans << "\n";
  }
  return 0;
}

