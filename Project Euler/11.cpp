#include <algorithm>
#include <iostream>
using namespace std;
const int n = 20;
int a[n + 5][n + 5];
int main() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j + 3 <= n; j++) {
      int res = 1;
      for (int k = 0; k <= 3; k++) res *= a[i][j + k];
      ans = max(ans, res);
    }
  for (int i = 1; i + 3 <= n; i++)
    for (int j = 1; j <= n; j++) {
      int res = 1;
      for (int k = 0; k <= 3; k++) res *= a[i + k][j];
      ans = max(ans, res);
    }
  for (int i = 1; i + 3 <= n; i++)
    for (int j = 1; j + 3 <= n; j++) {
      int res = 1;
      for (int k = 0; k <= 3; k++) res *= a[i + k][j + k];
      ans = max(ans, res);
    }
  for (int i = 1; i + 3 <= n; i++)
    for (int j = 4; j <= n; j++) {
      int res = 1;
      for (int k = 0; k <= 3; k++) res *= a[i + k][j - k];
      ans = max(ans, res);
    }
  cout << ans << endl;
}