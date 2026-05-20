#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll s;
  cin >> s;
  ll h, m, ss;
  h = s / 3600;
  m = (s % 3600) / 60;
  ss = s % 60;
  cout << h << ':' << m << ':' << ss << '\n';
  return 0;
}

