// Problem: F - Cumulative Cumulative Cumulative Sum
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest
// 2022（AtCoder Beginner Contest 256) URL:
// https://atcoder.jp/contests/abc256/tasks/abc256_f Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const long long mod = 998244353;
const long long inv2 = 499122177;
struct BIT {
  long long a[200005];
  int n;
  void init(int n) { this->n = n; }
  int lowbit(int x) { return x & (-x); }
  void add(int x, long long y) {
    while (x <= n) {
      a[x] = (a[x] + y) % mod;
      x += lowbit(x);
    }
  }
  long long sum(int x) {
    long long ans = 0;
    while (x) {
      ans = (ans + a[x]) % mod;
      x -= lowbit(x);
    }
    return (ans + mod) % mod;
  }
} tr1, tr2, tr3;
long long a[200005];
int main() {
  int n, q;
  cin >> n >> q;
  tr1.init(n), tr2.init(n), tr3.init(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tr1.add(i, 1ll * i * i % mod * a[i] % mod);
    tr2.add(i, i * a[i] % mod);
    tr3.add(i, a[i]);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      long long x, v;
      cin >> x >> v;
      int delta = (v - a[x] + mod) % mod;
      tr1.add(x, x * x % mod * delta % mod);
      tr2.add(x, x * delta % mod);
      tr3.add(x, delta);
      a[x] = v;
    } else {
      long long x;
      cin >> x;
      long long res2 = tr1.sum(x);
      long long res1 = (2 * x + 3) * tr2.sum(x) % mod;
      long long res0 = ((x + 1) * (x + 2) % mod * tr3.sum(x)) % mod;
      cout << ((res2 - res1 + res0) % mod * inv2 % mod + mod) % mod << endl;
    }
  }
  return 0;
}