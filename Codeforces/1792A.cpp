// Problem: A. GamingForces
// Contest: Codeforces - Educational Codeforces Round 142 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1792/problem/A
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt += (x == 1);
    }
    n -= (cnt / 2) * 2;
    cout << n + cnt / 2 << endl;
  }
  return 0;
}