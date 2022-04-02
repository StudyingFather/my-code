// Problem: A. Deletions of Two Adjacent Letters
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, c;
    cin >> s >> c;
    int len = s.length();
    bool ans = false;
    for (int i = 0; i < len; i++)
      if (s[i] == c[0] && i % 2 == 0 && (len - i - 1) % 2 == 0) ans = true;
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}