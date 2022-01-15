// Problem: P1522 [USACO2.4]牛的旅行 Cow Tours
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1522
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
struct dsu {
  int fa[155], n;
  void init(int n) {
    this->n = n;
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    fa[y] = x;
  }
  bool together(int x, int y) { return find(x) == find(y); }
} ds;
struct point {
  int x, y;
} p[155];
char str[155];
double d[155][155], maxd[155], ad[155];
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  int n;
  scanf("%d", &n);
  ds.init(n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int c;
      scanf("%1d", &c);
      if (i == j)
        d[i][j] = 0;
      else if (c == 1) {
        d[i][j] = dist(p[i].x, p[i].y, p[j].x, p[j].y);
        ds.merge(i, j);
      } else
        d[i][j] = 1 << 30;
    }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (ds.together(i, j)) maxd[i] = max(maxd[i], d[i][j]);
    ad[ds.find(i)] = max(ad[ds.find(i)], maxd[i]);
  }
  double ans = 1 << 30;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!ds.together(i, j))
        ans = min(ans,
                  max(maxd[i] + maxd[j] + dist(p[i].x, p[i].y, p[j].x, p[j].y),
                      max(ad[ds.find(i)], ad[ds.find(j)])));
  printf("%.6lf\n", ans);
  return 0;
}