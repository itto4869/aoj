#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (1) {
    cin >> s;
    if (s == "-") {
      break;
    }
    ll n = s.length();
    ll m;
    cin >> m;
    ll idx = 0;
    ll h;
    for(int i = 0; i < m; i++) {
      cin >> h;
      idx = (idx + h) % n;
    }

    for(int i = 0; i < n; i++) {
      cout << s[(idx + i) % n];
    }

    cout << "\n";
  }
  return 0;
}

