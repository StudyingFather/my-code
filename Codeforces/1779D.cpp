// Problem: Boris and His Amazing Haircut
// Contest: Codeforces - Hello 2023
// URL: https://m1.codeforces.com/contest/1779/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct seg {
  int maxa[800005];
  void pushup(int rt) { maxa[rt] = max(maxa[rt << 1], maxa[rt << 1 | 1]); }
  void build(int rt, int l, int r, int *a) {
    if (l == r) {
      maxa[rt] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid, a);
    build(rt << 1 | 1, mid + 1, r, a);
    pushup(rt);
  }
  int query(int rt, int cl, int cr, int l, int r) {
    if (cr < l || r < cl) return 0;
    if (l <= cl && cr <= r) return maxa[rt];
    int mid = (cl + cr) >> 1;
    return max(query(rt << 1, cl, mid, l, r),
               query(rt << 1 | 1, mid + 1, cr, l, r));
  }
} tr;
int a[200005], b[200005], x[200005];
vector<int> v[200005];
bool calc(int ind, int cnt, int n) {
  int siz = v[ind].size();
  cnt--;
  for (int i = 0; i < siz - 1; i++)
    if (tr.query(1, 1, n, v[ind][i], v[ind][i + 1]) > x[ind]) cnt--;
  return cnt >= 0;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    bool ans = true;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    tr.build(1, 1, n, b);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) v[i].clear();
    sort(x + 1, x + m + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] > b[i]) {
        int ind = lower_bound(x + 1, x + m + 1, b[i]) - x;
        if (x[ind] != b[i] || ind == m + 1) {
          ans = false;
          break;
        }
        v[ind].push_back(i);
      } else if (a[i] < b[i]) {
        ans = false;
        break;
      }
    }
    if (!ans) {
      cout << "NO" << '\n';
      continue;
    }
    int cnt = 1;
    for (int i = m; i > 0; i--) {
      if (x[i] == x[i - 1])
        cnt++;
      else {
        ans &= calc(i, cnt, n);
        cnt = 1;
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}