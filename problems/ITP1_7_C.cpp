#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll r, c;
  cin >> r >> c;
  vector<vector<ll>> a(r + 1, vector<ll>(c + 1));

  ll ssum = 0;
  for(ll i = 0; i < r; i++) {
    ll sum = 0;
    for(ll j = 0; j < c; j++) {
      ll x;
      cin >> x;
      sum += x;
      ssum += x;
      a[i][j] = x;
    }
    a[i][c] = sum;
  }

  a[r][c] = ssum;
  for(ll j = 0; j < c; j++) {
    ll sum = 0;
    for(ll i = 0; i < r; i++) {
      sum += a[i][j];
    }
    a[r][j] = sum;
  }

  for(ll i = 0; i < r + 1; i++) {
    cp::println_range(a[i]);
  }
  return 0;
}

