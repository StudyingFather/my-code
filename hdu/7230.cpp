// Problem: Stormwind
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7230
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 262 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    int ans = 0;
    cin >> n >> m >> k;
    for (int w = 1; w <= n; w++) {
      int h = k / w + (k % w != 0);
      if (m < h) continue;
      ans = max(ans, n / w - 1 + m / h - 1);
    }
    cout << ans << endl;
  }
  return 0;
}