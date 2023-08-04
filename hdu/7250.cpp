// Problem: Even Tree Split
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7250
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 524 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;
vector<int> e[100005];
int siz[100005];
void dfs(int u, int fa) {
  siz[u] = 1;
  for (auto v : e[u]) {
    if (v != fa) {
      dfs(v, u);
      siz[u] += siz[v];
    }
  }
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
  int T;
  cin >> T;
  while (T--) {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    dfs(1, 1);
    for (int i = 2; i <= n; i++) cnt += (siz[i] % 2 == 0);
    cout << fpow(2, cnt) - 1 << endl;
  }
  return 0;
}