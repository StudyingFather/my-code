// Problem: C - Dash
// Contest: AtCoder - NS Solutions Corporation Programming Contest 2023（AtCoder
// Beginner Contest 303） URL: https://atcoder.jp/contests/abc303/tasks/abc303_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
#include <string>
using namespace std;
typedef pair<int, int> pii;
set<pii> se;
int main() {
  int n, m, h, k;
  cin >> n >> m >> h >> k;
  string op;
  cin >> op;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    se.insert(make_pair(x, y));
  }
  int x = 0, y = 0;
  bool ans = true;
  for (auto c : op) {
    if (c == 'R') x++;
    if (c == 'L') x--;
    if (c == 'U') y++;
    if (c == 'D') y--;
    h--;
    if (h < 0) {
      ans = false;
      break;
    }
    if (se.count(make_pair(x, y)) && h < k) {
      h = k;
      se.erase(make_pair(x, y));
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}