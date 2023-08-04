// Problem: B - Qual B
// Contest: AtCoder - Toyota Programming Contest 2023 Spring Qual B（AtCoder
// Beginner Contest 290） URL: https://atcoder.jp/contests/abc290/tasks/abc290_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int n, k, cnt = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      cnt++;
      if (cnt > k) s[i] = 'x';
    }
  }
  cout << s << endl;
  return 0;
}