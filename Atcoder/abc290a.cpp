// Problem: A - Contest Result
// Contest: AtCoder - Toyota Programming Contest 2023 Spring Qual B（AtCoder
// Beginner Contest 290） URL: https://atcoder.jp/contests/abc290/tasks/abc290_a
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[105];
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    ans += a[x];
  }
  cout << ans << endl;
  return 0;
}