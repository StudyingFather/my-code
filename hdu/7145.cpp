// Problem: Path
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7145
// Memory Limit: 262 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
struct edge {
  int v, w, next;
} e[2000005];
int head[2000005], cnt;
long long dis[2000005];
bool vis[2000005];
int n, m, S, K;
void addedge(int u, int v, int w) {
  e[++cnt].v = v;
  e[cnt].w = w;
  e[cnt].next = head[u];
  head[u] = cnt;
}
void dijkstra(int s) {
  priority_queue<pii, vector<pii>, greater<pii> > q;
  set<int> se;
  dis[s] = 0;
  q.push(make_pair(0, s));
  for (int i = 1; i <= n; i++) se.insert(i);
  while (!q.empty()) {
    set<int> out, dse;
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    se.erase(u), vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if (u > n) w -= K;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push(make_pair(dis[v], v));
      }
      if (v > n)
        out.insert(v - n);
      else
        out.insert(v);
    }
    if (u > n) {
      for (set<int>::iterator it = se.begin(); it != se.end(); it++) {
        int v = *it;
        if (!out.count(v)) {
          if (dis[v] > dis[u]) {
            dis[v] = dis[u];
            q.push(make_pair(dis[v], v));
            dse.insert(v);
          }
        }
      }
      for (set<int>::iterator it = dse.begin(); it != dse.end(); it++)
        se.erase(*it);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    memset(dis, 63, sizeof(dis));
    cnt = 0;
    cin >> n >> m >> S >> K;
    for (int i = 1; i <= m; i++) {
      int x, y, w, t;
      cin >> x >> y >> w >> t;
      if (t == 1)
        addedge(x, y + n, w), addedge(x + n, y + n, w);
      else
        addedge(x, y, w), addedge(x + n, y, w);
    }
    dijkstra(S);
    for (int i = 1; i <= n; i++)
      cout << (vis[i] || vis[i + n] ? min(dis[i], dis[i + n]) : -1) << ' ';
    cout << endl;
  }
  return 0;
}