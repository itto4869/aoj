#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void call(ll n);
void check_num(ll n);
void include3(ll n);
void end_check_num(ll n);

ll i = 1;
ll x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  call(n);

  return 0;
}

void call(ll n) {
  i = 1;
  check_num(n);
}

void check_num(ll n) {
  x = i;
  if (x % 3 == 0) {
    cout << " " << i;
    end_check_num(n);
  }
  include3(n);
}

void include3(ll n) {
  if (x % 10 == 3) {
    cout << " " << i;
    end_check_num(n);
  }
  x /= 10;
  if (x) {
    include3(n);
  }
  end_check_num(n);
}

void end_check_num(ll n) {
  if (++i <= n) {
    check_num(n);
  }

  cout << endl;
  exit(0);
}