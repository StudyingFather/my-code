// Problem: Ironforge
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7224
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 524 MB
// Time Limit: 6000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 200000 + 5;
int b[maxn], l[maxn], r[maxn];
vector<int> ppos[maxn];
set<int> f[maxn];
void divide(int pos, int x) {
  int x0 = x, d = 2;
  for (; x != 1 && d * d <= x0; d++) {
    if (x % d == 0) f[pos].insert(d), ppos[d].push_back(pos);
    while (x % d == 0) x /= d;
  }
  if (x != 1) f[pos].insert(x), ppos[x].push_back(pos);
}
bool find_factor(int p, int l, int r) {
  auto it = lower_bound(ppos[p].begin(), ppos[p].end(), l);
  return it != ppos[p].end() && *it <= r;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 1; i <= maxn - 5; i++) ppos[i].clear(), f[i].clear();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      divide(i, a);
    }
    for (int i = 1; i < n; i++) cin >> b[i];
    for (int i = n; i; i--) {
      r[i] = i;
      while (r[i] < n && find_factor(b[r[i]], i, r[i])) r[i] = r[r[i] + 1];
    }
    for (int i = 1; i <= n; i++) {
      l[i] = i;
      while (1) {
        bool flag = false;
        while (l[i] > 1 && find_factor(b[l[i] - 1], l[i], r[i])) {
          l[i] = l[l[i] - 1];
          flag = true;
        }
        while (r[i] < n && find_factor(b[r[i]], l[i], r[i])) {
          r[i] = r[r[i] + 1];
          flag = true;
        }
        if (!flag) break;
      }
    }
    while (m--) {
      int s, t;
      cin >> s >> t;
      cout << (l[s] <= t && t <= r[s] ? "Yes" : "No") << endl;
    }
  }
  return 0;
}