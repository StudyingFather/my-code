// Problem: E - Transition Game
// Contest: AtCoder - AtCoder Beginner Contest 296
// URL: https://atcoder.jp/contests/abc296/tasks/abc296_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200000;
int a[maxn + 5];
bool vis[maxn + 5], res[maxn + 5];
vector<int> e[maxn + 5];
vector<int> path;
void dfs(int u) {
  vis[u] = true;
  path.push_back(u);
  int v = a[u];
  if (vis[v]) {
    bool inloop = false;
    for (auto x : path) {
      if (x == v) inloop = true;
      if (inloop) {
        res[a[x]] = true;
      }
    }
  } else
    dfs(v);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      path.clear();
      dfs(i);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += res[i];
  cout << ans << endl;
  return 0;
}