// Problem: C - Gap Existence
// Contest: AtCoder - AtCoder Beginner Contest 296
// URL: https://atcoder.jp/contests/abc296/tasks/abc296_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  bool ans = false;
  for (auto a : s) {
    ans |= s.count(a + x);
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}