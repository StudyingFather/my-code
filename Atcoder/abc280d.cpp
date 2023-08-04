// Problem: D - Factorial and Multiple
// Contest: AtCoder - Denso Create Programming Contest 2022 Winter(AtCoder
// Beginner Contest 280) URL: https://atcoder.jp/contests/abc280/tasks/abc280_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <map>
using namespace std;
map<long long, int> factor;
void init(long long k) {
  long long k0 = k;
  for (long long i = 2; i * i <= k0; i++) {
    while (k % i == 0) {
      k /= i;
      factor[i]++;
    }
  }
  if (k != 1) factor[k]++;
}
int calc(long long x, long long y) {
  int ans = 0;
  while (x % y == 0) x /= y, ans++;
  return ans;
}
int main() {
  long long k;
  cin >> k;
  init(k);
  long long ans = 0;
  for (auto p : factor) {
    long long f = p.first, e = p.second, res = 0;
    for (int i = 1; e > 0; i++, res += f) {
      e -= calc(i * f, f);
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}