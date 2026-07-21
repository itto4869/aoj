#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  reverse(v.begin(), v.end());
  cp::println_range(v);
  return 0;
}

