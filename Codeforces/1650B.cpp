// Problem: B. DIV + MOD
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/B
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
    int l, r, a;
    cin >> l >> r >> a;
    int pos = r / a * a;
    if (pos <= l)
      cout << r / a + r % a << endl;
    else
      cout << max((pos - 1) / a + (a - 1), r / a + r % a) << endl;
  }
  return 0;
}