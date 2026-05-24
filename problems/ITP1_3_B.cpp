#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll i = 1;
  while (1) {
    ll x;
    cin >> x;
    if (x == 0) {
      break;
    }

    cout << "Case " << i << ": " << x << "\n";
    i++;
  }
  return 0;
}

