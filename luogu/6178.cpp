// Problem: P6178 【模板】Matrix-Tree 定理
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6178
// Memory Limit: 250 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int mod = 1000000007;
long long f[305][305];
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (t == 0) {
      f[u][u] += w, f[v][v] += w;
      f[u][v] -= w, f[v][u] -= w;
    } else {
      f[v][v] += w;
      f[u][v] -= w;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = (f[i][j] % mod + mod) % mod;
  long long det = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (f[j][i] != 0) {
        swap(f[i], f[j]);
        if (i != j) det = mod - det;
        break;
      }
    }
    if (!f[i][i]) {
      det = 0;
      break;
    }
    det = det * f[i][i] % mod;
    for (int k = i + 1; k <= n; k++) {
      int t = f[k][i] * fpow(f[i][i], mod - 2) % mod;
      for (int l = i; l <= n; l++)
        f[k][l] = ((f[k][l] - t * f[i][l]) % mod + mod) % mod;
    }
  }
  cout << det << endl;
  return 0;
}