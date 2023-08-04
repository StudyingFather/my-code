// Problem: E - A Gift From the Stars
// Contest: AtCoder - NS Solutions Corporation Programming Contest 2023（AtCoder
// Beginner Contest 303)
// URL: https://atcoder.jp/contests/abc303/tasks/abc303_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200000;
vector<int> e[maxn + 5];
vector<int> res;
int t[maxn + 5];
bool vis[maxn + 5];
void dfs(int u, int op) {
  vis[u] = true;
  if (op == 1) res.push_back(t[u]);
  for (auto v : e[u]) {
    if (vis[v]) continue;
    dfs(v, (op + 1) % 3);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
    t[u]++, t[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      dfs(i, 0);
      break;
    }
  }
  sort(res.begin(), res.end());
  for (auto x : res) cout << x << ' ';
  cout << endl;
  return 0;
}