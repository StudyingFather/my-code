// Problem: F - Xor Minimization
// Contest: AtCoder - AtCoder Beginner Contest 281
// URL: https://atcoder.jp/contests/abc281/tasks/abc281_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;
int dfs(int d, vector<int> v) {
  if (d < 0) return 0;
  vector<int> s, t;
  for (auto x : v) {
    if (x & (1 << d))
      s.push_back(x);
    else
      t.push_back(x);
  }
  if (s.empty()) return dfs(d - 1, t);
  if (t.empty()) return dfs(d - 1, s);
  return min(dfs(d - 1, s), dfs(d - 1, t)) | (1 << d);
}
int main() {
  vector<int> v;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  cout << dfs(29, v) << endl;
  return 0;
}