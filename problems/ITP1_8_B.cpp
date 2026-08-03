#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    string x;
    cin >> x;
    if (x == "0") {
      break;
    }

    ll res = 0;
    for(char c : x) {
      res += c - '0';
    }

    cout << res << '\n';
  }
  return 0;
}

