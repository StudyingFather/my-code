// Problem: C - One Quadrillion and One Dalmatians
// Contest: AtCoder - AtCoder Beginner Contest 171
// URL: https://atcoder.jp/contests/abc171/tasks/abc171_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
long long ps[15];
long long fpow(long long x, long long y) {
  long long ans = 1;
  while (y) ans *= x, y--;
  return ans;
}
int main() {
  string s;
  long long n;
  cin >> n;
  ps[0] = 1;
  for (int i = 1; i <= 10; i++) ps[i] = ps[i - 1] + fpow(26, i);
  for (int i = 10; i >= 0; i--) {
    int x = (n - ps[i]) / fpow(26, i);
    if (n < ps[i] && s.empty()) continue;
    n -= (x + 1) * fpow(26, i);
    s.push_back('a' + x);
  }
  cout << s << endl;
  return 0;
}