// Problem: F - Union of Two Sets
// Contest: AtCoder - HHKB Programming Contest 2022 Winter
// (AtCoder Beginner Contest 282)
// URL: https://atcoder.jp/contests/abc282/tasks/abc282_f
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cmath>
#include <iostream>
using namespace std;
int f[4005][15];
int main() {
  ios::sync_with_stdio(false);
  int n, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 0; i + (1 << j) - 1 <= n; j++) f[i][j] = ++cnt;
  cout << cnt << endl;
  for (int i = 1; i <= n; i++)
    for (int j = 0; i + (1 << j) - 1 <= n; j++)
      cout << i << ' ' << i + (1 << j) - 1 << endl;
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int k = log2(r - l + 1);
    cout << f[l][k] << ' ' << f[r - (1 << k) + 1][k] << endl;
  }
  return 0;
}