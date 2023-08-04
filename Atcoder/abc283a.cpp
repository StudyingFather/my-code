// Problem: A - Power
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022 Winter(AtCoder
// Beginner Contest 283) URL: https://atcoder.jp/contests/abc283/tasks/abc283_a
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int a, b, ans = 1;
  cin >> a >> b;
  for (int i = 1; i <= b; i++) ans = ans * a;
  cout << ans << endl;
  return 0;
}