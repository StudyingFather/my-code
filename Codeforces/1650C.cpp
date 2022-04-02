// Problem: C. Weight of the System of Nested Segments
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
struct point {
  int x, w, id;
  bool operator<(const point& a) const {
    return w < a.w || (w == a.w && x < a.x);
  }
} a[200005];
bool cmp(const point& a, const point& b) { return a.x < b.x; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> a[i].x >> a[i].w;
      a[i].id = i;
    }
    sort(a + 1, a + m + 1);
    sort(a + 1, a + 2 * n + 1, cmp);
    long long sum = 0;
    for (int i = 1; i <= 2 * n; i++) sum += a[i].w;
    cout << sum << endl;
    for (int i = 1; i <= n; i++)
      cout << a[i].id << ' ' << a[2 * n + 1 - i].id << endl;
    cout << endl;
  }
  return 0;
}