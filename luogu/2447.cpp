// Problem: P2447 [SDOI2010]外星千足虫
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2447
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstdio>
using namespace std;
int n, m;
int a[2005][1005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) scanf("%1d", &a[i][j]);
    scanf("%d", &a[i][n + 1]);
    a[i][0] = i;
  }
  for (int i = 1; i <= n; i++) {
    bool flag = false;
    for (int j = i; j <= m; j++) {
      if (a[j][i]) {
        flag = true;
        swap(a[i], a[j]);
        break;
      }
    }
    if (!flag) {
      puts("Cannot Determine");
      return 0;
    }
    for (int j = i + 1; j <= m; j++)
      if (a[j][i])
        for (int k = i; k <= n + 1; k++) a[j][k] ^= a[i][k];
  }
  for (int i = n; i; i--) {
    for (int j = i - 1; j; j--)
      if (a[j][i])
        for (int k = i; k <= n + 1; k++) a[j][k] ^= a[i][k];
  }
  int ans = a[1][0];
  for (int i = 1; i <= n; i++) ans = max(ans, a[i][0]);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) puts(a[i][n + 1] ? "?y7M#" : "Earth");
  return 0;
}