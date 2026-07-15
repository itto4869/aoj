#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 0;
  while (1) {
    ll h, w;
    cin >> h >> w;

    if ((h == 0) && (w == 0)) {
      break;
    }

    if (t > 0) {
      cout << "\n";
    }
    string ans = "";
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i == 0) || (i == (h - 1))) {
          ans += "#";
        } else if ((j == 0) || (j == (w - 1))) {
          ans += "#";
        } else {
          ans += ".";
        }
      }

      ans += "\n";
    }

    cout << ans;

    t += 1;
  }
  return 0;
}

