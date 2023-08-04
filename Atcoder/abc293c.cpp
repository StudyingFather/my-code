// Problem: C - Make Takahashi Happy
// Contest: AtCoder - AtCoder Beginner Contest 293
// URL: https://atcoder.jp/contests/abc293/tasks/abc293_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
using namespace std;
int a[15][15];
int h, w, cnt;
set<int> se;
void dfs(int x, int y) {
  se.insert(a[x][y]);
  if (x == h && y == w) cnt++;
  if (x + 1 <= h && !se.count(a[x + 1][y])) dfs(x + 1, y);
  if (y + 1 <= w && !se.count(a[x][y + 1])) {
    dfs(x, y + 1);
  }
  se.erase(a[x][y]);
}
int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) cin >> a[i][j];
  dfs(1, 1);
  cout << cnt << endl;
  return 0;
}