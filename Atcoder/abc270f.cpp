// Problem: F - Transportation
// Contest: AtCoder - TOYOTA MOTOR CORPORATION Programming Contest 2022(AtCoder
// Beginner Contest 270) URL: https://atcoder.jp/contests/abc270/tasks/abc270_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct edge {
  int u, v, w;
  bool operator<(const edge& a) const { return w < a.w; }
} oe[600005], e[600005];
struct dsu {
  int fa[600005];
  void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    fa[x] = y;
    return true;
  }
} ds;
int x[200005], y[200005];
long long mst(int n, int m) {
  sort(e + 1, e + m + 1);
  ds.init(n);
  long long ans = 0;
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    if (ds.merge(u, v)) ans += w, cnt++;
  }
  return cnt == n - 1 ? ans : 1ll << 60;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> y[i];
  for (int i = 1; i <= m; i++) cin >> oe[i].u >> oe[i].v >> oe[i].w;
  long long ans = 1ll << 60;

  memcpy(e, oe, sizeof(oe));
  ans = min(ans, mst(n, m));

  memcpy(e, oe, sizeof(oe));
  for (int i = 1; i <= n; i++)
    e[i + m].u = i, e[i + m].v = n + 1, e[i + m].w = x[i];
  ans = min(ans, mst(n + 1, m + n));

  memcpy(e, oe, sizeof(oe));
  for (int i = 1; i <= n; i++)
    e[i + m].u = i, e[i + m].v = n + 1, e[i + m].w = y[i];
  ans = min(ans, mst(n + 1, m + n));

  memcpy(e, oe, sizeof(oe));
  for (int i = 1; i <= n; i++)
    e[i + m].u = i, e[i + m].v = n + 1, e[i + m].w = x[i];
  for (int i = 1; i <= n; i++)
    e[i + m + n].u = i, e[i + m + n].v = n + 2, e[i + m + n].w = y[i];
  ans = min(ans, mst(n + 2, m + 2 * n));

  cout << ans << endl;
  return 0;
}