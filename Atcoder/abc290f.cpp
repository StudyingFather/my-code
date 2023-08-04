// Problem: F - Maximum Diameter
// Contest: AtCoder - Toyota Programming Contest 2023 Spring Qual B（AtCoder
// Beginner Contest 290） URL: https://atcoder.jp/contests/abc290/tasks/abc290_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int mod = 998244353;
const int maxn = 3000000;
long long f[maxn + 5], invf[maxn + 5];
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long C(int x, int y) { return f[x] * invf[y] % mod * invf[x - y] % mod; }
int main() {
  ios::sync_with_stdio(false);
  f[0] = 1;
  for (int i = 1; i <= maxn; i++) f[i] = f[i - 1] * i % mod;
  invf[maxn] = fpow(f[maxn], mod - 2);
  for (int i = maxn - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (C(2 * n - 3, n - 1) + C(2 * n - 4, n - 1) * n) % mod << endl;
  }
  return 0;
}