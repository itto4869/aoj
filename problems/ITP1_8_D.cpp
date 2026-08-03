#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, p;
  cin >> s >> p;
  int n = s.length();
  int m = p.length();
  for(int i = 0; i < n; i++) {
    bool ok = true;
    for(int j = 0; j < m; j++) {
      if (s[(i + j) % n] != p[j]) {
        ok = false;
      }
    }

    if (ok) {
      cout << "Yes" << "\n";
      return 0;
    }
  }

  cout << "No" << "\n";
  return 0;
}

