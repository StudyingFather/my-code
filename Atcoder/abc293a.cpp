// Problem: A - Swap Odd and Even
// Contest: AtCoder - AtCoder Beginner Contest 293
// URL: https://atcoder.jp/contests/abc293/tasks/abc293_a
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
  string s;
  cin >> s;
  int l = s.length();
  for (int i = 0; i < l; i += 2) cout << s[i + 1] << s[i];
  cout << endl;
  return 0;
}