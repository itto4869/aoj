#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b, c;
  ll ans = 0;
  cin >> a >> b >> c;
  for (int x = a; x <= b; x++) {
    if (c % x == 0) {
      ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}

