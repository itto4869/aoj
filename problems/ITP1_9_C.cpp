#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  string a, b;
  ll s_a = 0;
  ll s_b = 0;
  for(ll i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > b) {
      s_a += 3;
    } else if (a < b) {
      s_b += 3;
    } else {
      s_a += 1;
      s_b += 1;
    }
  }

  cout << s_a << " " << s_b << "\n";
  return 0;
}

