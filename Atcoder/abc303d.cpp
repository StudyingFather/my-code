// Problem: D - Shift vs. CapsLock
// Contest: AtCoder - NS Solutions Corporation Programming Contest 2023（AtCoder
// Beginner Contest 303） URL: https://atcoder.jp/contests/abc303/tasks/abc303_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long i64;
const int maxn = 300000;
i64 f[maxn + 5][2];
string s;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  cin >> s;
  int n = s.length();
  memset(f, 63, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) f[i][j ^ 1] = min(f[i][j ^ 1], f[i][j] + z);
    for (int j = 0; j < 2; j++) {
      bool sta = (s[i] == 'A');
      if (j == sta)
        f[i + 1][j] = min(f[i + 1][j], f[i][j] + x);
      else
        f[i + 1][j] = min(f[i + 1][j], f[i][j] + y);
    }
  }
  cout << min(f[n][0], f[n][1]) << endl;
  return 0;
}