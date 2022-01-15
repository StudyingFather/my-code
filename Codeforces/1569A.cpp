// Problem: A. Balanced Substring
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/0
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
using namespace std;
int a[55];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i - 1] == 'a');
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int len = j - i + 1, x = a[j] - a[i - 1];
        if (x == len - x) {
          cout << i << ' ' << j << endl;
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) cout << "-1 -1" << endl;
  }
  return 0;
}