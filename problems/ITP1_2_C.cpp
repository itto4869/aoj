#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> v(3);
  cin >> v[0] >> v[1] >> v[2];

  sort(v.begin(), v.end());

  cout << v[0] << " " << v[1] << " " << v[2] << '\n';
  return 0;
}

