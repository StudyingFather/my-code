// Problem: D. Inconvenient Pairs
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200000;
const int maxx = 1000000 + 1;
int x[maxn + 5], y[maxn + 5];
struct point {
  int x, y, c;
} p[maxn + 5];
struct BIT {
  long long a[maxx + 5];
  int n;
  void init(int n) {
    memset(a, 0, sizeof(a));
    this->n = n;
  }
  int lowbit(int x) { return x & (-x); }
  void update(int x, int y) {
    while (x <= n) {
      a[x] += y;
      x += lowbit(x);
    }
  }
  int query(int x) {
    long long ans = 0;
    while (x) {
      ans += a[x];
      x -= lowbit(x);
    }
    return ans;
  }
} tr;
bool cmp1(const point &a, const point &b) { return a.x < b.x; }
bool cmp2(const point &a, const point &b) { return a.y < b.y; }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    long long ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> x[i], x[i]++;
    for (int i = 1; i <= m; i++) cin >> y[i], y[i]++;
    for (int i = 1; i <= k; i++) {
      cin >> p[i].x >> p[i].y;
      p[i].x++, p[i].y++;
      if (*lower_bound(x + 1, x + n + 1, p[i].x) == p[i].x) p[i].c |= 1;
      if (*lower_bound(y + 1, y + m + 1, p[i].y) == p[i].y) p[i].c |= 2;
    }
    sort(p + 1, p + k + 1, cmp1);
    tr.init(maxx);
    for (int i = 1; i <= k; i++) {
      if (p[i].c == 2) {
        int k = upper_bound(x + 1, x + n + 1, p[i - 1].x) - x - 1;
        ans += tr.query(p[i].x) - tr.query(x[k]);
        tr.update(p[i].x, 1);
      }
    }
    sort(p + 1, p + k + 1, cmp2);
    tr.init(maxx);
    for (int i = 1; i <= k; i++) {
      if (p[i].c == 1) {
        int k = upper_bound(y + 1, y + m + 1, p[i - 1].y) - y - 1;
        ans += tr.query(p[i].y) - tr.query(y[k]);
        tr.update(p[i].y, 1);
      }
    }
    cout << ans << endl;
  }
  return 0;
}