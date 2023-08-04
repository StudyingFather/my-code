// Problem: B. Vova and Trophies
// Contest: Codeforces - Educational Codeforces Round 55 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1082/problem/B
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  s.push_back('S');
  int cnt = 0, ans = 0;
  for (auto c : s) cnt += (c == 'G');
  int len = 0, dis = 0, lastl = -1;
  for (auto c : s)
    if (c == 'G') {
      len++;
    } else {
      if (len > 0) {
        ans = max(ans, len + 1);
        if (dis == 1) ans = max(ans, lastl + len + 1);
        lastl = len, len = 0, dis = 1;
      } else {
        dis++;
      }
    }
  cout << min(ans, cnt) << endl;
  return 0;
}