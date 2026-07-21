#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<vector<ll>> vec(12, vector<ll>(10, 0));
  for(int i = 0; i < n; i++) {
    ll b, f, r, v;
    cin >> b >> f >> r >> v;
    vec[3 * (b - 1) + f - 1][r - 1] += v;
  }

  for(int i = 1; i <= 12; i++) {
    for(int j = 0; j < 10; j++) {
      cout << " " << vec[i - 1][j];
    }
    cout << "\n";
    if (i % 3 == 0 && i != 12) {
      cout << "####################" << "\n";
    }
  } 
  return 0;
}

