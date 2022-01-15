// Problem: C. Jury Meeting
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
const int mod = 998244353;
const int maxn = 200000;
long long f[maxn + 5], invf[maxn + 5];
int a[maxn + 5];
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long A(int x, int y) {
  if (x < y) return 0;
  return f[x] * invf[x - y] % mod;
}
int main() {
  int t;
  cin >> t;
  f[0] = 1;
  for (int i = 1; i <= maxn; i++) f[i] = f[i - 1] * i % mod;
  invf[maxn] = fpow(f[maxn], mod - 2);
  for (int i = maxn - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt1 = 0, cnt2 = 0;
    long long ans = f[n];
    for (int i = n; i; i--)
      if (a[i] == a[n])
        cnt1++;
      else if (a[i] == a[n] - 1)
        cnt2++;
    if (cnt1 >= 2)
      cout << f[n] << endl;
    else {
      for (int i = 1; i <= n; i++)
        ans = ((ans - A(i - 1, cnt2) * f[n - cnt2 - 1]) % mod + mod) % mod;
      cout << ans << endl;
    }
  }
  return 0;
}