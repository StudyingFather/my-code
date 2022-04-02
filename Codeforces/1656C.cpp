// Problem: C. Make Equal With Mod
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool flag1 = false, flag2 = false;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 1) flag1 = true;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
      if (a[i] + 1 == a[i + 1]) flag2 = true;
    cout << (!(flag1 && flag2) ? "YES" : "NO") << endl;
  }
  return 0;
}