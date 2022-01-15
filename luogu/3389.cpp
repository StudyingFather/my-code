// Problem: P3389 【模板】高斯消元法
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3389
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstdio>
using namespace std;
int n;
double a[105][105];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n + 1; j++) scanf("%lf", &a[i][j]);
  // Step 1: 化为阶梯形矩阵
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
    double t = a[i][i];
    for (int j = i; j <= n + 1; j++) a[i][j] /= t;
    for (int k = i + 1; k <= n; k++) {
      double t = a[k][i];
      for (int l = i; l <= n + 1; l++) a[k][l] -= t * a[i][l];
    }
  }
  // Step 2: 化为简化阶梯形矩阵
  for (int i = n; i; i--) {
    for (int j = 1; j < i; j++) {
      double t = a[j][i];
      for (int k = i; k <= n + 1; k++) a[j][k] -= t * a[i][k];
    }
  }
  for (int i = 1; i <= n; i++) printf("%.2lf\n", a[i][n + 1]);
  return 0;
}