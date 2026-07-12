#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double r;
  cin >> r;

  double l = 2.0 * r * M_PI;
  double s = r * r * M_PI;

  cp::print_fixed(6, s, l);
  return 0;
}

