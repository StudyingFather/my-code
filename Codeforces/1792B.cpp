// Problem: B. Stand-up Comedian
// Contest: Codeforces - Educational Codeforces Round 142 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1792/problem/B
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[5];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 4; i++) cin >> a[i];
    if (a[1] == 0) {
      cout << 1 << endl;
    } else {
      int tmp = min(a[2], a[3]);
      int ans = a[1] + tmp * 2;
      a[2] -= tmp;
      a[3] -= tmp;
      if (a[2] > 0) {
        ans += min(a[1] + 1, a[2] + a[4]);
      } else {
        ans += min(a[1] + 1, a[3] + a[4]);
      }
      cout << ans << endl;
    }
  }
  return 0;
}