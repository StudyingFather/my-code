// Problem: P7960 [NOIP2021] 报数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7960
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int maxn = 10000000 + 1000;
int vis[maxn + 5], lis[maxn + 5], cnt;
bool check(int x) {
  while (x) {
    if (x % 10 == 7) return false;
    x /= 10;
  }
  return true;
}
void init() {
  for (int i = 1; i <= maxn; i++)
    if (vis[i] == 0) {
      if (check(i)) {
        vis[i] = ++cnt;
        lis[cnt] = i;
      } else
        for (int j = 1; i * j <= maxn; j++) vis[i * j] = -1;
    }
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  init();
  while (T--) {
    int x;
    cin >> x;
    if (vis[x] == -1)
      cout << -1 << endl;
    else {
      cout << lis[vis[x] + 1] << endl;
    }
  }
  cerr << cnt;
  return 0;
}