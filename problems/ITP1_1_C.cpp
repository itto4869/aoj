#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;
  cin >> a >> b;
  ll area = a * b;
  ll perimeter = 2 * (a + b);
  cout << area << ' ' << perimeter << '\n';
  return 0;
}

