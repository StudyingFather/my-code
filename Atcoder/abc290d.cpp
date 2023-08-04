// Problem: D - Marking
// Contest: AtCoder - Toyota Programming Contest 2023 Spring Qual B（AtCoder
// Beginner Contest 290） URL: https://atcoder.jp/contests/abc290/tasks/abc290_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d, k;
    cin >> n >> d >> k;
    int ls = lcm(n, d) / d;
    cout << (1ll * (k - 1) * d + (k - 1) / ls) % n << endl;
  }
  return 0;
}