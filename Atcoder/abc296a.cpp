// Problem: A - Alternately
// Contest: AtCoder - AtCoder Beginner Contest 296
// URL: https://atcoder.jp/contests/abc296/tasks/abc296_a
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
  bool ans = true;
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}