#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string w, t;
  cin >> w;

  ll ans = 0;
  while (1) {
    cin >> t;

    if (t == "END_OF_TEXT") {
      break;
    }

    if (t.length() == w.length()) {
      bool ok = true;
      int n = t.length();
      for(int i = 0; i < n; i++) {
        if (tolower(t[i]) != tolower(w[i])) {
          ok = false;
          break;
        }
      }

      if (ok) {
        ans += 1;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}

