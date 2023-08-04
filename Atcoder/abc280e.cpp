// Problem: E - Critical Hit
// Contest: AtCoder - Denso Create Programming Contest 2022 Winter(AtCoder
// Beginner Contest 280) URL: https://atcoder.jp/contests/abc280/tasks/abc280_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int mod = 998244353;
long long f[200005];
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
  int n, p;
  cin >> n >> p;
  long long inv100 = fpow(100, mod - 2);
  for (int i = 2; i <= n + 1; i++) {
    f[i] = f[i - 2] * p % mod * inv100 % mod +
           f[i - 1] * (100 - p) % mod * inv100 % mod;
    f[i] = (f[i] + 1) % mod;
  }
  cout << f[n + 1] << endl;
  return 0;
}