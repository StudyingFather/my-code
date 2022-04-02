// Problem: P2491 [SDOI2011] 消防
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2491
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct edge {
  int v, w;
  edge(int v = 0, int w = 0) {
    this->v = v;
    this->w = w;
  }
};
const int maxn = 300000 + 5;
vector<edge> e[maxn];
int dep[maxn], f[maxn], c;
int dia[maxn], cnt, pres[maxn], posts[maxn];
bool vis[maxn];
int n, s;
void dfs(int u, int fa) {
  f[u] = fa;
  for (auto ed : e[u]) {
    if (ed.v == fa || vis[ed.v]) continue;
    dep[ed.v] = dep[u] + ed.w;
    if (dep[ed.v] > dep[c]) c = ed.v;
    dfs(ed.v, u);
  }
}
void get_diameter() {
  dfs(1, 0);
  dep[c] = 0;
  dfs(c, 0);
  for (int u = c; u; u = f[u]) {
    dia[++cnt] = u;
    pres[cnt] = dep[u];
  }
  reverse(dia + 1, dia + cnt + 1);
  reverse(pres + 1, pres + cnt + 1);
  for (int i = cnt; i > 0; i--) posts[i] = pres[cnt] - pres[i];
}
namespace sub1 {
void solve() {
  int minecc = 1 << 30;
  for (int i = 1; i <= cnt; i++)
    for (int j = i; j <= cnt; j++) {
      if (pres[j] - pres[i] <= s) {
        memset(vis, 0, sizeof(vis));
        for (int k = i; k <= j; k++) vis[dia[k]] = true;
        int ecc = 0;
        for (int k = i; k <= j; k++) {
          dep[dia[k]] = 0, c = 0;
          dfs(dia[k], 0);
          ecc = max(ecc, dep[c]);
        }
        minecc = min(minecc, ecc);
      }
    }
  cout << minecc << endl;
}
}  // namespace sub1
namespace sub2 {
void solve() {
  int minecc = 1 << 30;
  int l = 1, r = 1;
  for (; l <= cnt; l++) {
    while (r <= cnt && pres[r + 1] - pres[l] <= s) r++;
    memset(vis, 0, sizeof(vis));
    for (int k = l; k <= r; k++) vis[dia[k]] = 1;
    int ecc = 0;
    for (int k = l; k <= r; k++) {
      dep[dia[k]] = 0, c = 0;
      dfs(dia[k], 0);
      ecc = max(ecc, dep[c]);
    }
    minecc = min(minecc, ecc);
  }
  cout << minecc << endl;
}
}  // namespace sub2
int maxd[maxn];
namespace sub3 {
bool check(int ecc) {
  int l = 1, r = cnt;
  while (l < cnt && pres[l + 1] <= ecc) l++;
  while (r > l && posts[r - 1] <= ecc) r--;
  if (pres[r] - pres[l] > s) return false;
  int d = 0;
  for (int i = l + 1; i < r; i++) d = max(d, maxd[i]);
  return d <= ecc;
}
void solve() {
  for (int i = 1; i <= cnt; i++) vis[dia[i]] = true;
  for (int i = 1; i <= cnt; i++) {
    dep[dia[i]] = 0, c = 0;
    dfs(dia[i], 0);
    maxd[i] = dep[c];
  }
  int l = 0, r = 1 << 30, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans << endl;
}
}  // namespace sub3
namespace sub4 {
void solve() {
  for (int i = 1; i <= cnt; i++) vis[dia[i]] = true;
  int maxd = 0;
  for (int i = 1; i <= cnt; i++) {
    dep[dia[i]] = 0, c = 0;
    dfs(dia[i], 0);
    maxd = max(dep[c], maxd);
  }
  int l = 1, r = 1;
  int minecc = 1 << 30;
  for (; l <= cnt; l++) {
    while (r <= cnt && pres[r + 1] - pres[l] <= s) r++;
    minecc = min(max(maxd, max(pres[l], posts[r])), minecc);
  }
  cout << minecc << endl;
}
}  // namespace sub4
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  get_diameter();
  sub4::solve();
  return 0;
}