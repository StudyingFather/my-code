// Problem: D - M<=ab
// Contest: AtCoder - AtCoder Beginner Contest 296
// URL: https://atcoder.jp/contests/abc296/tasks/abc296_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long i64;
int main() {
  i64 n, m;
  cin >> n >> m;
  if (n <= (1 << 20) && n * n < m) {
    cout << -1 << endl;
    return 0;
  }
  i64 ans = 1ll << 60, maxa = sqrt(m) + 1;
  for (i64 a = 1; a <= maxa; a++) {
    i64 b = m / a + (m % a != 0);
    if (b > n) continue;
    ans = min(ans, a * b);
  }
  cout << ans << endl;
  return 0;
}