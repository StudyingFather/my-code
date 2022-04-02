// Problem: P2887 [USACO07NOV]Sunscreen G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2887
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
struct seg {
  int l, r;
  bool operator<(const seg& a) const {
    return r < a.r || (r == a.r && l < a.l);
  }
} a[5005];
typedef pair<int, int> pii;
pii b[5005];
int main() {
  int c, l;
  cin >> c >> l;
  for (int i = 1; i <= c; i++) cin >> a[i].l >> a[i].r;
  for (int i = 1; i <= l; i++) cin >> b[i].first >> b[i].second;
  sort(a + 1, a + c + 1);
  sort(b + 1, b + l + 1);
  int ans = 0;
  for (int i = 1; i <= c; i++)
    for (int j = 1; j <= l; j++) {
      if (b[j].second > 0 && a[i].l <= b[j].first && b[j].first <= a[i].r) {
        b[j].second--;
        ans++;
        break;
      }
    }
  cout << ans << endl;
  return 0;
}