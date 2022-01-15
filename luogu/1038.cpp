// Problem: P1038 [NOIP2003 提高组] 神经网络
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1038
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct edge {
  int v, w;
};
vector<edge> e[105];
queue<int> q;
int c[105], u[105];
int in[105];
int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> u[i];
    c[i] -= u[i];
  }
  for (int i = 1; i <= p; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    in[v]++;
  }
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i), c[i] += u[i];
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      c[v] += w * max(c[u], 0);
      in[v]--;
      if (!in[v]) q.push(v);
    }
  }
  bool flag = false;
  for (int i = 1; i <= n; i++)
    if (e[i].size() == 0 && c[i] > 0) {
      cout << i << ' ' << c[i] << endl;
      flag = true;
    }
  if (!flag) cout << "NULL" << endl;
  return 0;
}