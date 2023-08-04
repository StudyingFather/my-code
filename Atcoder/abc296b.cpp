// Problem: B - Chessboard
// Contest: AtCoder - AtCoder Beginner Contest 296
// URL: https://atcoder.jp/contests/abc296/tasks/abc296_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int r = 0, c = 0;
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 8; j++)
      if (s[j] == '*') {
        r = 8 - i;
        c = j;
      }
  }
  cout << (char)('a' + c) << r << endl;
  return 0;
}