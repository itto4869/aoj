#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    ll m, f, r;
    cin >> m >> f >> r;
    if ((m == -1) & (f == -1) & (r == -1)) {
      break;
    }

    if ((m == -1) | (f == -1)) {
      cout << 'F' << "\n";
    } else if ((m + f >= 80)) {
      cout << 'A' << "\n";
    } else if ((m + f >= 65)) {
      cout << 'B' << "\n";
    } else if ((m + f >= 50)) {
      cout << 'C' << "\n";
    } else if ((r >= 50)) {
      cout << 'C' << "\n";
    } else if ((m + f >= 30)) {
      cout << 'D' << "\n";
    } else {
      cout << 'F' << "\n";
    }
  }
  return 0;
}

