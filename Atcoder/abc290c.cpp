// Problem: C - Max MEX
// Contest: AtCoder - Toyota Programming Contest 2023 Spring Qual B（AtCoder
// Beginner Contest 290） URL: https://atcoder.jp/contests/abc290/tasks/abc290_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int a[300005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i] == ans) {
      ans++;
      if (ans == k) break;
    }
  }
  cout << ans << endl;
  return 0;
}