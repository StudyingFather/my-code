// Problem: D. Twist the Permutation
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[2005], res[2005], curp[2005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      curp[a[i]] = i;
    }
    for (int p = n; p; p--) {
      res[p] = (curp[p] == p ? 0 : curp[p]);
      for (int i = 1; i <= p; i++) {
        curp[i] -= res[p];
        if (curp[i] <= 0) curp[i] += p;
      }
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << endl;
  }
  return 0;
}