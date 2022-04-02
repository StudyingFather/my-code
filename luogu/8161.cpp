// Problem: P8161 [JOI 2022 Final] 自学 (Self Study)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8161
// Memory Limit: 537 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
  long long a, b;
} p[300005];
int n, m;
bool cmp(const node& a, const node& b) {
  return a.a > b.a || (a.a == b.a && a.b > b.b);
}
bool check(long long x) {
  long long rem = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i].a * m >= x)
      rem += m - (x / p[i].a + (x % p[i].a != 0));
    else {
      rem -= (x - p[i].a * m) / p[i].b + ((x - p[i].a * m) % p[i].b != 0);
      if (rem < 0) return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i].a;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].b;
    if (p[i].b > p[i].a) p[i].a = p[i].b;
  }
  sort(p + 1, p + n + 1, cmp);
  long long l = 1, r = 1ll << 62, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}