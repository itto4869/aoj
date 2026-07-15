#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    ll h, w;
    cin >> h >> w;

    if ((h == 0) && (w == 0)) {
      break;
    }

    string ans = "";
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i % 2) == 0) {
          if ((j % 2) == 0) {
            ans += "#";
          } else {
            ans += ".";
          }
        } else {
          if ((j % 2) == 0) {
            ans += ".";
          } else {
            ans += "#";
          }
        }
      }
      ans += "\n";
    }

    cout << ans << "\n";
  }
  return 0;
}

