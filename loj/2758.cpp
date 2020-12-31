// Problem: #2758. 「JOI 2014 Final」年轮蛋糕
// Contest: LibreOJ
// URL: https://loj.ac/problem/2758
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: StudyingFather
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
long long a[200005], s[200005];
int n;
int find(long long x, int pos) {
  int l = pos, r = pos + n, ans = pos + n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (s[mid] - s[pos - 1] >= x)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
bool check(long long x) {
  for (int i = 1; i <= n; i++) {
    int j = find(x, i);
    if (j >= i + n) continue;
    int k = find(x, j + 1);
    if (k >= i + n) continue;
    if (s[i + n - 1] - s[k] < x) continue;
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];
  for (int i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + a[i];
  long long l = 0, r = 1e14, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}