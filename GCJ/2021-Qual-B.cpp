// Problem: Moons and Umbrellas
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam
// 2021 URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// Author: StudyingFather
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1e9;
int f[1005][2];
string s;
int main() {
  int T;
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    int x, y;
    cin >> x >> y;
    cin >> s;
    int l = s.length();
    f[0][0] = f[0][1] = 0;
    if (s[0] == 'C') f[0][1] = INF;
    if (s[0] == 'J') f[0][0] = INF;
    for (int i = 1; i < l; i++) {
      if (s[i] == 'C') {
        f[i][0] = min(f[i - 1][0], f[i - 1][1] + y);
        f[i][1] = INF;
      } else if (s[i] == 'J') {
        f[i][1] = min(f[i - 1][1], f[i - 1][0] + x);
        f[i][0] = INF;
      } else {
        f[i][0] = min(f[i - 1][0], f[i - 1][1] + y);
        f[i][1] = min(f[i - 1][1], f[i - 1][0] + x);
      }
    }
    cout << "Case #" << kase << ": " << min(f[l - 1][0], f[l - 1][1]) << endl;
  }
  return 0;
}