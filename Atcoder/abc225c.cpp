// Problem: C - Calendar Validator
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest
// 225) URL: https://atcoder.jp/contests/abc225/tasks/abc225_c Memory Limit:
// 1024 MB Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int b[10005][15];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
      if (i == 1 && j == 1) continue;
      if (j == 1) {
        if (b[i - 1][j] + 7 != b[i][j]) {
          cout << "No" << endl;
          return 0;
        }
      } else {
        if (b[i][j - 1] + 1 != b[i][j] ||
            (b[i][j - 1] - 1) / 7 != (b[i][j] - 1) / 7) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  cout << "Yes" << endl;
  return 0;
}