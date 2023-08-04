// Problem: E - Find Permutation
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA
// SYSTEMS） URL: https://atcoder.jp/contests/abc291/tasks/abc291_e Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> e[200005];
queue<int> q;
int t[200005], f[200005];
int main() {
  int n, m, maxf = 0;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    t[y]++;
  }
  for (int i = 1; i <= n; i++)
    if (!t[i]) q.push(i), f[i] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : e[u]) {
      f[v] = max(f[v], f[u] + 1);
      maxf = max(maxf, f[v]);
      t[v]--;
      if (!t[v]) q.push(v);
    }
  }
  if (maxf != n)
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    cout << endl;
  }
  return 0;
}