// Problem: A - Pawn on a Grid
// Contest: AtCoder - Denso Create Programming Contest 2022 Winter(AtCoder
// Beginner Contest 280) URL: https://atcoder.jp/contests/abc280/tasks/abc280_a
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (auto c : s) ans += (c == '#');
  }
  cout << ans << endl;
  return 0;
}