// Problem: Backpack
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7140
// Memory Limit: 65 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bitset>
#include <iostream>
using namespace std;
struct item {
  int v, w;
} a[2005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    bitset<1024> f[2][1024];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].v >> a[i].w;
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < (1 << 10); j++) {
        int ii = i & 1;
        f[ii][j] = f[ii ^ 1][j] | (f[ii ^ 1][j ^ a[i].w] << a[i].v);
      }
    int ans = -1;
    for (int i = 0; i < (1 << 10); i++)
      if (f[n & 1][i][m]) ans = i;
    cout << ans << endl;
  }
  return 0;
}