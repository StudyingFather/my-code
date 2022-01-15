#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<long long, int> pli;
long long a[100005], b[100005], c[100005];
set<pli> s[100005];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    long long sa = a[n];
    if (sa == 0) {
      map<long long, int> ma;
      for (int i = 1; i <= n; i++)
        if (ma[a[i]] == 0) ma[a[i]] = i;
      ma[0] = 0;
      while (m--) {
        long long x;
        cin >> x;
        if (ma.count(x))
          cout << ma[x] << endl;
        else
          cout << -1 << endl;
      }
      continue;
    }
    for (int i = 1; i <= n; i++) b[i] = c[i] = ((a[i] % sa) + sa) % sa;
    sort(c + 1, c + n + 1);
    int cnt = unique(c + 1, c + n + 1) - c - 1;
    for (int i = 1; i <= cnt; i++) s[i].clear();
    for (int i = 1; i <= n; i++) {
      int x = lower_bound(c + 1, c + cnt + 1, b[i]) - c;
      s[x].insert(make_pair((long long)(-floor(1.0 * a[i] / sa)), i));
    }
    while (m--) {
      long long x;
      cin >> x;
      long long rem = ((x % sa) + sa) % sa;
      int pos = lower_bound(c + 1, c + cnt + 1, rem) - c;
      if (c[pos] != rem)
        cout << -1 << endl;
      else if (x == 0)
        cout << 0 << endl;
      else {
        long long leastt = (x - rem) / sa;
        if (s[pos].lower_bound(make_pair(-leastt, 0)) == s[pos].end()) {
          cout << -1 << endl;
          continue;
        }
        pli dst = *s[pos].lower_bound(make_pair(-leastt, 0));
        long long ans = (leastt + dst.first) * n + dst.second;
        cout << ans << endl;
      }
    }
  }
  return 0;
}