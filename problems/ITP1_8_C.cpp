#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  
  vector<ll> v(26, 0);
  while (cin >> s) {
    for(char c : s) {
      if (!isalpha(c)) {
        continue;
      }
      c = tolower(c);
      v[c - 'a'] += 1;
    }
  }

  for(int i = 0; i < 26; i++) {
    char res_c = 'a' + i;
    cout << res_c << " " << ":" << " " << v[i] << "\n";
  }

  return 0;
}

