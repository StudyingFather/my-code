// Problem: Controlled Inflation
// Contest: Google Coding Competitions - Round 1B 2022 - Code Jam 2022
// URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long f[1005][2], a[1005][2];
int main() {
  int T;
  ios::sync_with_stdio(false);
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    memset(f, 63, sizeof(f));
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
      a[i][0] = 1 << 30, a[i][1] = 0;
      for (int j = 1; j <= p; j++) {
        long long x;
        cin >> x;
        a[i][0] = min(a[i][0], x);
        a[i][1] = max(a[i][1], x);
      }
    }
    f[1][0] = a[1][1] + a[1][1] - a[1][0];
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 1; k++) {
          f[i][j] = min(f[i][j], f[i - 1][k] + abs(a[i - 1][k] - a[i][j ^ 1]) +
                                     abs(a[i][j] - a[i][j ^ 1]));
        }
    }
    cout << "Case #" << kase << ": " << min(f[n][0], f[n][1]) << endl;
  }
  return 0;
}