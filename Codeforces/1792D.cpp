// Problem: D. Fixed Prefix Permutations
// Contest: Codeforces - Educational Codeforces Round 142 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1792/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef array<int, 12> arr;
arr p[50005];
arr pos[50005];
int ans[50005];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    vector<pii> v[15];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      p[i].fill(0);
      ans[i] = 0;
      p[i][m + 1] = i;
      for (int j = 1; j <= m; j++) {
        cin >> p[i][j];
        pos[i][p[i][j]] = j;
      }
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
      arr tmp;
      tmp.fill(0);
      for (int j = 1; j <= m; j++) {
        tmp[j] = pos[i][j];
        int l = lower_bound(p + 1, p + n + 1, tmp) - p;
        tmp[j] = pos[i][j] + 1;
        int r = lower_bound(p + 1, p + n + 1, tmp) - p;
        tmp[j] = pos[i][j];
        if (l == r) break;
        v[j].emplace_back(l, r - 1);
      }
    }
    for (int i = 1; i <= m; i++) {
      int l = 0, r = 0;
      sort(v[i].begin(), v[i].end());
      for (auto [cl, cr] : v[i]) {
        if (cl > r) {
          for (int j = l; j <= r; j++) ans[p[j][m + 1]] = i;
          l = cl, r = cr;
        } else
          r = max(r, cr);
      }
      for (int j = l; j <= r; j++) ans[p[j][m + 1]] = i;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
  }
  cout << endl;
  return 0;
}