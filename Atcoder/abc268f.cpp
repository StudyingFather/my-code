// Problem: F - Best Concatenation
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022 Summer
// (AtCoder Beginner Contest 268)
// URL: https://atcoder.jp/contests/abc268/tasks/abc268_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
struct str {
  string s;
  double k;
} a[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s;
    int sum = 0, cnt = 0;
    for (auto c : a[i].s) {
      if (c == 'X')
        cnt++;
      else
        sum += c - '0';
    }
    if (cnt == 0)
      a[i].k = 1e30;
    else
      a[i].k = 1.0 * sum / cnt;
  }
  sort(a + 1, a + n + 1, [](str a, str b) { return a.k < b.k; });
  long long ans = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (auto c : a[i].s) {
      if (c == 'X')
        cnt++;
      else
        ans += (c - '0') * cnt;
    }
  }
  cout << ans << endl;
  return 0;
}