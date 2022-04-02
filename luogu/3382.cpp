// Problem: P3382 【模板】三分法
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3382
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
double a[25];
int n;
double f(double x) {
  double ans = 0, x0 = 1;
  for (int i = 0; i <= n; i++) ans += a[i] * x0, x0 *= x;
  return ans;
}
int main() {
  double l, r;
  cin >> n >> l >> r;
  for (int i = n; i >= 0; i--) cin >> a[i];
  while (r - l >= 1e-10) {
    double lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
    if (f(lmid) < f(rmid))
      l = lmid;
    else
      r = rmid;
  }
  cout << l << endl;
  return 0;
}