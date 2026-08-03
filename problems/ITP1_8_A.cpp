#include <bits/stdc++.h>
#include "cp/io.hpp"
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);
  for(char c : s) {
    if (isalpha(c)) {
      if (isupper(c)) {
        char res = tolower(c);
        cout << res;
      } else {
        char res = toupper(c);
        cout << res;
      }
    } else {
      cout << c;
    }
  }

  cout << '\n';
  return 0;
}

