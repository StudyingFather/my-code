// Problem: C - LRUD Instructions 2
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA
// SYSTEMS） URL: https://atcoder.jp/contests/abc291/tasks/abc291_c Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;
set<pii> se;
int main() {
  int n, x = 0, y = 0;
  bool ans = false;
  cin >> n;
  string s;
  cin >> s;
  se.insert(make_pair(0, 0));
  for (auto c : s) {
    switch (c) {
      case 'R':
        x++;
        break;
      case 'L':
        x--;
        break;
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
    }
    if (se.count(make_pair(x, y))) ans = true;
    se.insert(make_pair(x, y));
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}