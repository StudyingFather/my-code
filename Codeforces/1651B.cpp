// Problem: B. Prove Him Wrong
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1651/problem/B
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
    int n;
    cin >> n;
    if (n >= 20)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i = 1, j = 1; i <= n; i++, j *= 3) cout << j << ' ';
      cout << endl;
    }
  }
  return 0;
}