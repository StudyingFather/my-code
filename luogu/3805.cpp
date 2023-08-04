// Problem: P3805 【模板】manacher 算法
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3805
// Memory Limit: 512 MB
// Time Limit: 500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[11000005], t[25000005];
int d[25000005];
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
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
  return 0;
}