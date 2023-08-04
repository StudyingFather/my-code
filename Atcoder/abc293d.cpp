// Problem: D - Tying Rope
// Contest: AtCoder - AtCoder Beginner Contest 293
// URL: https://atcoder.jp/contests/abc293/tasks/abc293_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
struct dsu {
  int fa[400005];
  void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    fa[x] = y;
    return true;
  }
} ds;
int id(int a, string b) { return a * 2 - (b == "R"); }
int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  ds.init(2 * n);
  for (int i = 1; i <= 2 * n; i += 2) ds.merge(i, i + 1);
  for (int i = 1; i <= m; i++) {
    int a, c;
    string b, d;
    cin >> a >> b >> c >> d;
    int ida = id(a, b), idb = id(c, d);
    if (!ds.merge(ida, idb)) cnt++;
  }
  cout << cnt << ' ' << n - m << endl;
  return 0;
}