// Problem: C. Maximum Set
// Contest: Codeforces - Educational Codeforces Round 144 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1796/problem/C
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int mod = 998244353;
int c[25][25];
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) ans *= x, y--;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i <= 20; i++) c[i][0] = 1;
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  while (t--) {
    int l, r;
    long long ans = 0;
    cin >> l >> r;
    int cl = l, maxs = 1;
    while (cl <= r) cl *= 2, maxs++;
    maxs--;
    long long mulmax = fpow(3, maxs - 1);
    for (int i = maxs - 1; i >= 0; i--, mulmax = mulmax / 3 * 2) {
      int mins = r / mulmax;
      // cerr << mulmax << ' ' << mins << endl;
      if (mins >= l) ans = (ans + 1ll * (mins - l + 1) * c[maxs - 1][i]) % mod;
    }
    cout << maxs << ' ' << ans << endl;
  }
  return 0;
}