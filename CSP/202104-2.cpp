#include <iostream>
using namespace std;
int a[605][605], s[605][605];
int main() {
  int n, l, r, t;
  cin >> n >> l >> r >> t;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int minx = max(i - r, 1), maxx = min(i + r, n);
      int miny = max(j - r, 1), maxy = min(j + r, n);
      int sum = s[maxx][maxy] - s[maxx][miny - 1] - s[minx - 1][maxy] +
                s[minx - 1][miny - 1];
      ans += (sum <= t * (maxx - minx + 1) * (maxy - miny + 1));
    }
  }
  cout << ans << endl;
  return 0;
}