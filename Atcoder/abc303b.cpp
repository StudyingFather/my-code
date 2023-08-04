// Problem: B - Discord
// Contest: AtCoder - NS Solutions Corporation Programming Contest 2023（AtCoder
// Beginner Contest 303） URL: https://atcoder.jp/contests/abc303/tasks/abc303_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int maxn = 50;
bool vis[maxn + 5][maxn + 5];
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int last = -1;
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (j != 1) vis[last][x] = vis[x][last] = 1;
      last = x;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) ans += (vis[i][j] == 0);
  cout << ans << endl;
  return 0;
}