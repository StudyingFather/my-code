// Problem: G. Counting Shortcuts
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int mod = 1000000007;
vector<int> e[200005];
pii ed[200005];
int dis1[200005], dis2[200005];
int f1[200005], f2[200005];
int n, m, s, t;
void bfs(int s, int* dis, int* f) {
  queue<int> q;
  memset(dis, -1, sizeof(int) * (n + 1));
  memset(f, 0, sizeof(int) * (n + 1));
  dis[s] = 0, f[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : e[u])
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        f[v] = f[u];
        q.push(v);
      } else if (dis[v] == dis[u] + 1)
        f[v] = (f[v] + f[u]) % mod;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      ed[i] = make_pair(u, v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    bfs(s, dis1, f1);
    bfs(t, dis2, f2);
    long long ans = f1[t];
    for (int i = 1; i <= m; i++) {
      int u = ed[i].first, v = ed[i].second;
      if (dis1[u] == dis1[v]) {
        if (dis1[u] + dis2[v] == dis1[t])
          ans = (ans + 1ll * f1[u] * f2[v]) % mod;
        if (dis1[v] + dis2[u] == dis1[t])
          ans = (ans + 1ll * f1[v] * f2[u]) % mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}