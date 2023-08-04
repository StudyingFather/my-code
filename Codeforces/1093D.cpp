// Problem: D. Beautiful Graph
// Contest: Codeforces - Educational Codeforces Round 56 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1093/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;
vector<int> e[300005];
int vis[300005];
int cnt, siz;
bool dfs(int u, int c) {
  vis[u] = c;
  siz++, cnt += c;
  for (auto v : e[u]) {
    if (vis[v] == c) return false;
    if (vis[v] == -1) {
      if (!dfs(v, c ^ 1)) return false;
    }
  }
  return true;
}
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    long long ans = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear(), vis[i] = -1;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == -1) {
        cnt = 0, siz = 0;
        if (!dfs(i, 0)) {
          ans = 0;
          break;
        }
        ans = (ans * (fpow(2, cnt) + fpow(2, siz - cnt))) % mod;
      }
    }
    cout << ans << '\n';
  }
  cout << endl;
  return 0;
}