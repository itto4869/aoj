#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  ll min_v = 1000001;
  ll max_v = -1000001;
  ll sum_v = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;

    min_v = min(min_v, a);
    max_v = max(max_v, a);
    sum_v += a;
  }

  cp::println(min_v, max_v, sum_v);
  return 0;
}

