// Problem: P2879 [USACO07JAN]Tallest Cow S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2879
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;
set<pii> se;
int d[10005];
int main() {
  int n, I, H, r;
  cin >> n >> I >> H >> r;
  d[1] += H, d[n + 1] -= H;
  while (r--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (se.count(make_pair(a, b))) continue;
    se.insert(make_pair(a, b));
    d[a + 1]--, d[b]++;
  }
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    cout << d[i] << endl;
  }
  return 0;
}