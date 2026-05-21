#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;
  cin >> a >> b;
  if (a > b) {
    cout << "a > b" << '\n';
  } else if (a == b) {
    cout << "a == b" << '\n';
  } else {
    cout << "a < b" << '\n';
  }
  return 0;
}