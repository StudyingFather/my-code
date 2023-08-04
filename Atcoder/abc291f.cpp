// Problem: F - Teleporter and Closed off
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA
// SYSTEMS） URL: https://atcoder.jp/contests/abc291/tasks/abc291_f Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
string s[100005];
int f[100005], g[100005];
int main() {
  memset(f, 63, sizeof(f));
  memset(g, 63, sizeof(g));
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> s[i];
  f[1] = g[n] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m && j < i; j++)
      if (s[i - j][j - 1] == '1') f[i] = min(f[i], f[i - j] + 1);
  for (int i = n - 1; i >= 1; i--)
    for (int j = 1; j <= m && i + j <= n; j++)
      if (s[i][j - 1] == '1') g[i] = min(g[i], g[i + j] + 1);
  for (int k = 2; k <= n - 1; k++) {
    int ans = inf;
    for (int i = k - 1; i >= 1 && i + m > k; i--)
      for (int j = k + 1; j <= n && j - i <= m; j++)
        if (s[i][j - i - 1] == '1') ans = min(ans, f[i] + g[j] + 1);
    if (ans == inf)
      cout << -1 << ' ';
    else
      cout << ans << ' ';
  }
  cout << endl;
  return 0;
}