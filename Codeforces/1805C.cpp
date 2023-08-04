// Problem: C. Place for a Selfie
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/C
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100000;
long long k[maxn + 5], a[maxn + 5], b[maxn + 5], c[maxn + 5];
long long delta(long long a, long long b, long long c) {
  return b * b - 4 * a * c;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i];
    sort(k + 1, k + n + 1);
    for (int i = 1; i <= m; i++) {
      int ind = lower_bound(k + 1, k + n + 1, b[i]) - k;
      int res;
      bool ans = false;
      if (ind != n + 1 && delta(a[i], b[i] - k[ind], c[i]) < 0) {
        ans = true;
        res = ind;
      } else if (ind != 1 && delta(a[i], b[i] - k[ind - 1], c[i]) < 0) {
        ans = true;
        res = ind - 1;
      }
      if (ans) {
        cout << "YES" << '\n';
        cout << k[res] << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
    cout << '\n';
  }
  cout.flush();
  return 0;
}