// Problem: A - Similar String
// Contest: AtCoder - NS Solutions Corporation Programming Contest 2023（AtCoder
// Beginner Contest 303） URL: https://atcoder.jp/contests/abc303/tasks/abc303_a
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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  bool ans = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (s[i] == '1' && t[i] == 'l') continue;
      if (s[i] == 'l' && t[i] == '1') continue;
      if (s[i] == '0' && t[i] == 'o') continue;
      if (s[i] == 'o' && t[i] == '0') continue;
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}