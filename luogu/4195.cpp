// Problem: P4195 【模板】扩展 BSGS/exBSGS
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4195
// Memory Limit: 128 MB
// Time Limit: 1500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
using namespace std;
void exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
long long fpow(long long x, long long y, long long p) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return ans;
}
long long exbsgs(long long a, long long p, long long b) {
  unordered_map<long long, int> table;
  a %= p, b %= p;
  if (b == 1 || p == 1) return 0;
  long long d = 1, gnum;
  int cnt = 0;
  while ((gnum = gcd(a, p)) != 1) {
    if (b % gnum != 0) return -1;
    b /= gnum, p /= gnum;
    d = d * (a / gnum) % p;
    cnt++;
    if (d == b) return cnt;
  }
  long long x, y;
  exgcd(d, p, x, y);
  x = (x % p + p) % p;
  b = b * x % p;
  long long sqrtp = ceil(sqrt(p));
  long long A = fpow(a, sqrtp, p);
  for (long long i = 0, j = b; i <= sqrtp; i++, j = j * a % p) table[j] = i;
  for (long long i = 1, j = A; i <= sqrtp; i++, j = j * A % p)
    if (table.count(j)) return sqrtp * i - table[j] + cnt;
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  long long a, p, b;
  while (cin >> a >> p >> b) {
    if (a == 0 && p == 0 && b == 0) break;
    long long ans = exbsgs(a, p, b);
    if (ans != -1)
      cout << ans << endl;
    else
      cout << "No Solution" << endl;
  }
  return 0;
}