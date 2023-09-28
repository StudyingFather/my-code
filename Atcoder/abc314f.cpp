// Problem: F - A Certain Game
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;
typedef long long i64;
const int maxn = 200000;
const int mod = 998244353;
struct dsu {
  int fa[2 * maxn + 5];
  void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    fa[y] = x;
    return true;
  }
} ds;
vector<int> e[2 * maxn + 5];
int leafcnt[2 * maxn + 5];
i64 ans[2 * maxn + 5];
i64 fpow(i64 x, i64 y) {
  i64 ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
i64 inv(i64 x) { return fpow(x, mod - 2); }
void dfs1(int u) {
  if (e[u].empty()) leafcnt[u]++;
  for (auto v : e[u]) {
    dfs1(v);
    leafcnt[u] += leafcnt[v];
  }
}
void dfs2(int u, i64 sum) {
  if (e[u].empty()) ans[u] = sum;
  for (auto v : e[u]) {
    dfs2(v, (sum + leafcnt[v] * inv(leafcnt[u])) % mod);
  }
}
int main() {
  int n;
  cin >> n;
  ds.init(2 * n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int fx = ds.find(x), fy = ds.find(y);
    int f = n + i;
    e[f].push_back(fx);
    e[f].push_back(fy);
    ds.merge(f, fx);
    ds.merge(f, fy);
  }
  dfs1(2 * n - 1);
  dfs2(2 * n - 1, 0);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}