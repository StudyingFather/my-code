// Problem: C - Rotate Colored Subsequence
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_c
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 200000;
string s;
vector<char> v[maxn + 5];
int c[maxn + 5], pos[maxn + 5];
int main() {
  int n, m;
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    v[c[i]].push_back(s[i]);
  }
  for (int i = 1; i <= m; i++) pos[i] = v[i].size() - 1;
  for (int i = 0; i < n; i++) {
    int col = c[i];
    cout << v[col][pos[col]];
    pos[col] = (pos[col] + 1) % v[col].size();
  }
  cout << endl;
  return 0;
}