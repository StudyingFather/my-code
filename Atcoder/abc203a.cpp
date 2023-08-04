// Problem: A - Chinchirorin
// Contest: AtCoder - AtCoder Beginner Contest 203（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc203/tasks/abc203_a
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b)
    cout << c << endl;
  else if (a == c)
    cout << b << endl;
  else if (b == c)
    cout << a << endl;
  else
    cout << 0 << endl;
  return 0;
}