// Problem: D. Mahmoud and a Dictionary
// Contest: Codeforces - Codeforces Round 396 (Div. 2)
// URL: https://codeforces.com/contest/766/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <map>
using namespace std;
const int maxn = 100000;
string a[maxn + 5];
map<string, int> ma;
struct dsu {
  int fa[2 * maxn + 5];
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
  bool together(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
} ds;
int main() {
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ma[a[i]] = i;
  }
  ds.init(2 * n);
  for (int i = 1; i <= m; i++) {
    int op;
    string s, t;
    cin >> op >> s >> t;
    if (op == 1) {
      if (ds.together(ma[t], n + ma[s]) || ds.together(ma[s], n + ma[t])) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
        ds.merge(ma[s], ma[t]);
        ds.merge(n + ma[s], n + ma[t]);
      }
    } else {
      if (ds.together(ma[t], ma[s]) || ds.together(n + ma[t], n + ma[s])) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
        ds.merge(n + ma[s], ma[t]);
        ds.merge(n + ma[t], ma[s]);
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    string s, t;
    cin >> s >> t;
    if (ds.together(ma[s], ma[t]))
      cout << 1 << '\n';
    else if (ds.together(ma[s], n + ma[t]))
      cout << 2 << '\n';
    else
      cout << 3 << '\n';
  }
  cout.flush();
  return 0;
}