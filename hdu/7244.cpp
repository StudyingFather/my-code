// Problem: Winner Prediction
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7244
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 524 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct graph {
  struct edge {
    int v, w, next;
  } e[250005];
  int head[2005], cur[2005], dis[2005];
  int s, t, cnt;
  void init(int s, int t) {
    this->s = s;
    this->t = t;
    cnt = 1;
    memset(head, 0, sizeof(head));
  }
  void addedge(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
  }
  bool bfs() {
    queue<int> q;
    memcpy(cur, head, sizeof(head));
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v, w = e[i].w;
        if (w && dis[v] == -1) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }
    return dis[t] != -1;
  }
  int dfs(int u, int maxf) {
    if (u == t) return maxf;
    int used = 0;
    for (int i = cur[u]; i; i = e[i].next) {
      cur[u] = i;
      int v = e[i].v, w = e[i].w;
      if (dis[v] == dis[u] + 1 && w) {
        int flow = dfs(v, min(w, maxf - used));
        e[i].w -= flow;
        e[i ^ 1].w += flow;
        used += flow;
        if (used == maxf) break;
      }
    }
    return used;
  }
  int maxFlow() {
    int ans = 0;
    while (bfs()) ans += dfs(s, INF);
    return ans;
  }
} g;
int score[505];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(score, 0, sizeof(score));
    int n, m1, m2, om = 0;
    cin >> n >> m1 >> m2;
    int s = n + m2 + 1, t = n + m2 + 2;
    g.init(s, t);
    for (int i = 1; i <= m1; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      if (z)
        score[x]++;
      else
        score[y]++;
    }
    for (int i = 1; i <= m2; i++) {
      int x, y;
      cin >> x >> y;
      if (x == 1 || y == 1) {
        score[1]++;
        continue;
      } else {
        g.addedge(s, n + i, 1);
        g.addedge(n + i, s, 0);
        g.addedge(n + i, x, 1);
        g.addedge(x, n + i, 0);
        g.addedge(n + i, y, 1);
        g.addedge(y, n + i, 0);
        om++;
      }
    }
    bool flag = true;
    for (int i = 2; i <= n; i++) {
      if (score[i] > score[1]) {
        cout << "NO" << endl;
        flag = false;
        break;
      } else {
        g.addedge(i, t, score[1] - score[i]);
        g.addedge(t, i, 0);
      }
    }
    if (!flag) continue;
    cout << (om == g.maxFlow() ? "YES" : "NO") << endl;
  }
  return 0;
}