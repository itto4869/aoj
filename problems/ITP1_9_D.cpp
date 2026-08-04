#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  ll q;
  cin >> q;

  for(ll i = 0; i < q; i++) {
    string op;
    cin >> op;
    if (op == "print") {
      ll a, b;
      cin >> a >> b;
      cout << s.substr(a, b - a + 1) << "\n";
    } else if (op == "reverse") {
      ll a, b;
      cin >> a >> b;
      reverse(s.begin() + a, s.begin() + b + 1);
    } else {
      ll a, b;
      cin >> a >> b;
      
      string t;
      cin >> t;

      s.replace(a, b - a + 1, t);
    }
  }
  return 0;
}

