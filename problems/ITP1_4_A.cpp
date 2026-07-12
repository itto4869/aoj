#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;
  cin >> a >> b;
  ll d = a / b;
  ll r = a % b;
  
  double f = double(a) / double(b);

  cp::print_fixed(5, d, r, f);
  return 0;
}

