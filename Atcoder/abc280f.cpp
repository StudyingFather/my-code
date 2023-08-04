// Problem: F - Pay or Receive
// Contest: AtCoder - Denso Create Programming Contest 2022 Winter(AtCoder
// Beginner Contest 280) URL: https://atcoder.jp/contests/abc280/tasks/abc280_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
struct dsu {
  int fa[100005], siz[100005];
  void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    fa[v] = u, siz[u] += siz[v];
    return true;
  }
  bool together(int u, int v) { return find(u) == find(v); }
  int size(int u) { return siz[find(u)]; }
} ds;
bool vis[100005], inf[100005], inque[100005];
vector<pii> e[100005];
long long dis[100005];
int n, m, q;
void dfs(int u) {
  vis[u] = true;
  for (auto ed : e[u]) {
    int v = ed.first, w = ed.second;
    if (vis[v]) {
      if (dis[v] != dis[u] + w) inf[ds.find(u)] = true;
    } else {
      dis[v] = dis[u] + w;
      dfs(v);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  ds.init(n);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    e[u].emplace_back(v, c);
    e[v].emplace_back(u, -c);
    ds.merge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    dfs(i);
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (!ds.together(u, v))
      cout << "nan" << '\n';
    else if (inf[ds.find(u)])
      cout << "inf" << '\n';
    else
      cout << dis[v] - dis[u] << '\n';
  }
  return 0;
}