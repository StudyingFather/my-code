// Problem: D. Maximum Subarray
// Contest: Codeforces - Educational Codeforces Round 144 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1796/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const long long inf = 1ll << 60;
long long sum[200005], ns[200005][25], nsmin[200005][25];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    long long x;
    long long ans = 0;
    cin >> n >> k >> x;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= k; j++) ns[i][j] = 0, nsmin[i][j] = inf;
    for (int i = 1; i <= n; i++) {
      cin >> sum[i];
      sum[i] += sum[i - 1];
    }
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= k; j++)
        if (j <= i && n - i >= k - j)
          ns[i][j] = sum[i] + j * x - (i - j) * x;
        else
          ns[i][j] = inf;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i && j <= k; j++) {
        nsmin[i][j] = ns[i][j];
        if (i - 1 >= 0 && j - 1 >= 0)
          nsmin[i][j] = min(nsmin[i][j], nsmin[i - 1][j - 1]);
        if (i - 1 >= 0) nsmin[i][j] = min(nsmin[i][j], nsmin[i - 1][j]);
        if (ns[i][j] != inf) ans = max(ans, ns[i][j] - nsmin[i][j]);
      }
    cout << ans << endl;
  }
  return 0;
}