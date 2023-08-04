// Problem: B - Inverse Prefix Sum
// Contest: AtCoder - Denso Create Programming Contest 2022 Winter(AtCoder
// Beginner Contest 280) URL: https://atcoder.jp/contests/abc280/tasks/abc280_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[15];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cout << a[i] - a[i - 1] << ' ';
  }
  cout << endl;
  return 0;
}