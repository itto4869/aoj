#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll w, h, x, y, r;
  cin >> w >> h >> x >> y >> r;

  if (((x - r) < 0) or ((x + r) > w) or ((y - r) < 0) or ((y + r) > h)) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
  }
  return 0;
}

