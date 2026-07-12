#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;
  string op;

  while (1) {
    cin >> a >> op >> b;

    if (op == "?") {
      break;
    } else if (op == "+") {
      cout << a + b << '\n';
    } else if (op == "-") {
      cout << a - b << '\n';
    } else if (op == "*") {
      cout << a * b << '\n';
    } else {
      cout << a / b << '\n';
    }
  }
  return 0;
}

