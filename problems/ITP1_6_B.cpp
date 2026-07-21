#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int cmap(char c) {
  switch (c)
  {
  case 'S':
    return 0;
  case 'H':
    return 1;
  case 'C':
    return 2;
  case 'D':
    return 3;
  default:
    return 4;
  }
}

char rmap(int x) {
  switch (x)
  {
  case 0:
    return 'S';
  case 1:
    return 'H';
  case 2:
    return 'C';
  case 3:
    return 'D';
  default:
    return 'E';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<vector<bool>> v(4, vector<bool>(13, false));
  for(int i = 0; i < n; i++) {
    char c;
    ll x;
    cin >> c >> x;
    ll idx = cmap(c);
    v[idx][x - 1] = true;
  }

  for(int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      if (!v[i][j]) {
        cout << rmap(i) << " " << j + 1 << '\n';
      }
    }
  }
  return 0;
}