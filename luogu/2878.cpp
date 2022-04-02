// Problem: P2878 [USACO07JAN]Protecting the Flowers S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2878
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
struct cow {
  int d, t;
  bool operator<(const cow &a) const { return 1.0 * d / t > 1.0 * a.d / a.t; }
} a[100005];
int main() {
  int n;
  cin >> n;
  long long sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].t >> a[i].d;
    sum += a[i].d;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    sum -= a[i].d;
    ans += sum * a[i].t * 2;
  }
  cout << ans << endl;
  return 0;
}