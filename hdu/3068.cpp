// Problem: 最长回文
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=3068
// Memory Limit: 32 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[110005], t[250005];
int d[250005];
int main() {
  ios::sync_with_stdio(false);
  while (cin >> s) {
    memset(d, 0, sizeof(d));
    memset(t, 0, sizeof(t));
    int sl = strlen(s), ans = 0;
    t[0] = '#';
    for (int i = 0; i < sl; i++) t[2 * i + 1] = s[i], t[2 * i + 2] = '#';
    int l = 0, r = -1, tl = strlen(t);
    for (int i = 0; i < tl; i++) {
      int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
      while (i - k >= 0 && i + k <= tl && t[i - k] == t[i + k]) k++;
      d[i] = --k;
      ans = max(ans, k);
      if (i + k > r) r = i + k, l = i - k;
    }
    cout << ans << endl;
  }
  return 0;
}