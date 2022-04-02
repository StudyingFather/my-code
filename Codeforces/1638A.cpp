// Problem: A. Reverse
// Contest: Codeforces - Codeforces Round #771 (Div. 2)
// URL: https://codeforces.com/contest/1638/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int a[505];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int p = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] != i) {
        p = i;
        break;
      }
    for (int i = 1; i <= n; i++)
      if (a[i] == p) {
        reverse(a + p, a + i + 1);
        break;
      }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
  }
  return 0;
}