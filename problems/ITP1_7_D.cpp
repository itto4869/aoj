#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, l;
  cin >> n >> m >> l;
  vector<vector<ll>> a(n, vector<ll>(m));
  vector<vector<ll>> b(m, vector<ll>(l));

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for(ll i = 0; i < m; i++) {
    for(ll j = 0; j < l; j++) {
      cin >> b[i][j];
    }
  }

  vector<vector<ll>> c(n, vector<ll>(l, 0));
  for(ll i = 0; i < n; i++) {
    for(ll k = 0; k < m; k++) {
      for(ll j = 0; j < l; j++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for(ll i = 0; i < n; i++) {
    cp::println_range(c[i]);
  }
  return 0;
}

