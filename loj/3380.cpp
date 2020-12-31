// Problem: #3380. 「CSP-S 2020」动物园
// Contest: LibreOJ
// URL: https://loj.ac/p/3380
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: StudyingFather
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
bool vis[65], disable[65];
int main() {
  freopen("zoo.in", "r", stdin);
  freopen("zoo.out", "w", stdout);
  ios::sync_with_stdio(false);
  int n, m, c, k;
  cin >> n >> m >> c >> k;
  for (int i = 1; i <= n; i++) {
    ull a;
    cin >> a;
    for (int j = k - 1; j >= 0; j--) vis[j] |= (a >> j) & 1;
  }
  for (int i = 1; i <= m; i++) {
    int p, q;
    cin >> p >> q;
    if (!vis[p]) disable[p] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < k; i++)
    if (disable[i]) cnt++;
  if (k - cnt == 64) {
    if (n)
      cout << ull(-n) << endl;
    else
      cout << "18446744073709551616" << endl;
  } else
    cout << (1ull << (k - cnt)) - n << endl;
  return 0;
}