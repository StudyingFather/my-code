// Problem: F - Exactly K Steps
// Contest: AtCoder - NEC Programming Contest 2022 (AtCoder Beginner Contest
// 267) URL: https://atcoder.jp/contests/abc267/tasks/abc267_f Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> e[200005], dia;
int dep[200005], fa[200005][25], s;
int ind[200005];
void dfs(int u, int f) {
  fa[u][0] = f;
  dep[u] = dep[f] + 1;
  if (dep[u] > dep[s]) s = u;
  for (auto v : e[u]) {
    if (v == f) continue;
    dfs(v, u);
  }
}
void calcfa(int u, int f) {
  for (int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (auto v : e[u]) {
    if (v == f) continue;
    calcfa(v, u);
  }
}
int solve(int u, int k) {
  for (int i = 20; i >= 0; i--) {
    if (k < (1 << i) || fa[u][i] == 0 || ind[fa[u][i]] != -1) continue;
    k -= 1 << i;
    u = fa[u][i];
  }
  if (k == 0) return u;
  if (ind[u] == -1) u = fa[u][0], k--;
  int siz = dia.size();
  if (ind[u] >= k)
    return dia[ind[u] - k];
  else if (ind[u] + k < siz)
    return dia[ind[u] + k];
  else
    return -1;
}
int main() {
  ios::sync_with_stdio(false);
  memset(ind, -1, sizeof(ind));
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  dfs(s, 0);
  for (int i = 1, u = s; u; i++, u = fa[u][0]) dia.push_back(u);
  reverse(dia.begin(), dia.end());
  int siz = dia.size();
  for (int i = 0; i < siz; i++) ind[dia[i]] = i;
  calcfa(dia[0], 0);
  int q;
  cin >> q;
  while (q--) {
    int u, k;
    cin >> u >> k;
    cout << solve(u, k) << endl;
  }
  return 0;
}