// Problem: D. A Wide, Wide Graph
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100000;
vector<int> e[maxn + 5];
vector<int> dia;
int dep[maxn + 5], dis[maxn + 5], f[maxn + 5];
int longdis[maxn + 5], cnt[maxn + 5];
int s, t, n;
bool vis[maxn + 5];
void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  f[u] = fa;
  if (dep[u] > dep[t]) t = u;
  for (auto v : e[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}
void update(int u, int fa, bool isroot) {
  if (!isroot) {
    longdis[u] = longdis[fa] + 1;
  }
  vis[u] = true;
  for (auto v : e[u]) {
    if (vis[v]) continue;
    update(v, u, false);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dep[0] = -1;
  dfs(1, 0);
  s = t;
  dfs(s, 0);
  int len = dep[t];
  for (int u = t; u != 0; u = f[u]) dia.push_back(u), vis[u] = true;
  int tmp = len;
  for (auto u : dia) {
    longdis[u] = tmp;
    tmp--;
  }
  reverse(dia.begin(), dia.end());
  tmp = len;
  for (auto u : dia) {
    longdis[u] = max(longdis[u], tmp);
    tmp--;
  }
  for (auto u : dia) update(u, 0, true);
  for (int i = 1; i <= n; i++) cnt[longdis[i]]++;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans += cnt[i - 1];
    cout << min(ans, n) << ' ';
  }
  cout << endl;
  return 0;
}