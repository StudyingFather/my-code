// Problem: #3197. 「eJOI2019」T 形覆盖
// Contest: LibreOJ
// URL: https://loj.ac/p/3197
// Memory Limit: 100 MB
// Time Limit: 1000 ms
// Author: StudyingFather
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
const int maxs = 1000005;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int a[1000005], vis[1000005], m, n, k;
int id(int x, int y) { return x * n + y; }
struct point {
  int x, y;
} p[1000005];
struct dsu {
  int fa[maxs], sum[maxs], mina[maxs], cnt1[maxs], cnt2[maxs];
  void init(int m, int n) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        int pos = id(i, j);
        sum[pos] = mina[pos] = a[pos];
        fa[pos] = pos;
        cnt1[pos] = 1;
      }
    for (int i = 1; i <= k; i++) {
      int pos = id(p[i].x, p[i].y);
      cnt1[pos] = 0;
      cnt2[pos] = 1;
      mina[pos] = 1e9;
    }
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[y] = x;
    cnt1[x] += cnt1[y];
    cnt2[x] += cnt2[y];
    sum[x] += sum[y];
    mina[x] = min(mina[x], mina[y]);
  }
} se;
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> a[id(i, j)];
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> p[i].x >> p[i].y;
  se.init(m, n);
  for (int i = 1; i <= k; i++) {
    int x = p[i].x, y = p[i].y;
    for (int j = 0; j <= 3; j++) {
      int nx = x + dx[j], ny = y + dy[j];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      se.merge(id(x, y), id(nx, ny));
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int pos = se.find(id(p[i].x, p[i].y));
    if (vis[pos]) continue;
    if (se.cnt1[pos] < 3 * se.cnt2[pos]) {
      cout << "No" << endl;
      return 0;
    } else if (se.cnt1[pos] == 3 * se.cnt2[pos])
      ans += se.sum[pos];
    else  // se.cnt1[pos] == 3 * se.cnt2[pos] + 1
      ans += se.sum[pos] - se.mina[pos];
    vis[pos] = 1;
  }
  cout << ans << endl;
  return 0;
}