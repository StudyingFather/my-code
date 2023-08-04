// Problem: B. Asterisk-Minor Template
// Contest: Codeforces - Educational Codeforces Round 144 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1796/problem/B
// Author : StudyingFather
// Site : https://studyingfather.com
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
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0]) {
      cout << "YES" << endl;
      cout << a[0] << '*' << endl;
    } else if (a[a.length() - 1] == b[b.length() - 1]) {
      cout << "YES" << endl;
      cout << '*' << a[a.length() - 1] << endl;
    } else {
      int la = a.length(), lb = b.length();
      int ind = 0;
      bool ans = false;
      for (int i = 0; i + 1 < la; i++) {
        for (int j = 0; j + 1 < lb; j++) {
          if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
            ans = true;
            ind = i;
            break;
          }
        }
        if (ans) break;
      }
      if (ans) {
        cout << "YES" << endl;
        cout << '*' << a[ind] << a[ind + 1] << '*' << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}