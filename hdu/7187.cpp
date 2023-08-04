// Problem: Slipper
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7187
// Memory Limit: 524 MB
// Time Limit: 10000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<long long, int> pii;
struct edge {
  int v, w, next;
} e[10000005];
int head[3000005], cnt;
void addedge(int u, int v, int w) {
  e[++cnt].v = v;
  e[cnt].w = w;
  e[cnt].next = head[u];
  head[u] = cnt;
}
int dep[1000005];
void dfs(int u, int fa) {
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v != fa) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
}
long long dis[3000005];
bool vis[3000005];
long long dijkstra(int s, int t) {
  priority_queue<pii, vector<pii>, greater<pii> > q;
  memset(vis, 0, sizeof(vis));
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push(make_pair(dis[v], v));
      }
    }
  }
  return dis[t];
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k, p, s, t;
    cin >> n;
    cnt = 0;
    memset(head, 0, 3 * n * sizeof(int));
    for (int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      addedge(u, v, w);
      addedge(v, u, w);
    }
    dep[1] = 1;
    dfs(1, 1);
    for (int u = 1; u <= n; u++) {
      addedge(u, dep[u] + n, 0);
      addedge(dep[u] + 2 * n, u, 0);
    }
    cin >> k >> p >> s >> t;
    for (int i = 1; i + k <= n; i++) {
      addedge(i + n, i + k + 2 * n, p);
      addedge(i + k + n, i + 2 * n, p);
    }
    cout << dijkstra(s, t) << endl;
  }
  return 0;
}