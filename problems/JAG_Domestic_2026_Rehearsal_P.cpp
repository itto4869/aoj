#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    ll a, b;
    cin >> a >> b;
    if ((a == 0) and (b == 0)) {
      return 0;
    } 
    ll ans;
    ans = a * b;
    cout << ans << '\n';
  }
}

