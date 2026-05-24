#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    ll x, y;
    cin >> x >> y;
    if ((x == 0) and (y == 0)) {
      break;
    }

    ll a = min(x, y);
    ll b = max(x, y);

    cout << a << " " << b << "\n";
  }
  return 0;
}

