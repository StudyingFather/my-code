// Problem: P4783 【模板】矩阵求逆
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4783
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int MOD = 1000000007;
long long a[405][805];
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y % 2) ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) a[i][i + n] = 1;
  for (int i = 1; i <= n; i++) {
    bool flag = false;
    for (int j = i; j <= n; j++)
      if (a[j][i] != 0) {
        swap(a[i], a[j]);
        flag = true;
        break;
      }
    if (!flag) {
      puts("No Solution");
      return 0;
    }
    long long t = a[i][i];
    for (int j = i; j <= 2 * n; j++) a[i][j] = a[i][j] * fpow(t, MOD - 2) % MOD;
    for (int k = i + 1; k <= n; k++) {
      long long t = a[k][i];
      for (int l = i; l <= 2 * n; l++)
        a[k][l] = ((a[k][l] - t * a[i][l]) % MOD + MOD) % MOD;
    }
  }
  for (int i = n; i; i--) {
    for (int j = i - 1; j; j--) {
      long long t = a[j][i];
      for (int k = i; k <= 2 * n; k++)
        a[j][k] = ((a[j][k] - t * a[i][k]) % MOD + MOD) % MOD;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << a[i][j + n] << ' ';
    cout << endl;
  }
  return 0;
}