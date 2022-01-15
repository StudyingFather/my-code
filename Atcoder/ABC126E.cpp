// Problem: E - 1 or 2
// Contest: AtCoder - AtCoder Beginner Contest 126
// URL: https://atcoder.jp/contests/abc126/tasks/abc126_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
struct dsu {
  int n, fa[100005];
  void init(int n) {
    this->n = n;
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
    }
  }
  int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    fa[x] = y;
    return 1;
  }
} ds;
int main() {
  int n, m, ans;
  cin >> n >> m;
  ans = n;
  ds.init(n);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ans -= ds.merge(a, b);
  }
  cout << ans << endl;
  return 0;
}