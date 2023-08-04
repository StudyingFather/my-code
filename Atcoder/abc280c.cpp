// Problem: C - Extra Charactor
// Contest: AtCoder - Denso Create Programming Contest 2022 Winter(AtCoder
// Beginner Contest 280) URL: https://atcoder.jp/contests/abc280/tasks/abc280_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int ls = s.length();
  for (int i = 0; i < ls; i++) {
    if (s[i] != t[i]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << ls + 1 << endl;
  return 0;
}