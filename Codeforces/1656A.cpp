// Problem: A. Good Pairs
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int minx = 1 << 30, maxx = 0, minp, maxp;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x < minx) minx = x, minp = i;
      if (x > maxx) maxx = x, maxp = i;
    }
    cout << minp << ' ' << maxp << endl;
  }
  return 0;
}