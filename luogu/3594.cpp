// Problem: P3594 [POI2015] WIL
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3594
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <deque>
#include <iostream>
using namespace std;
long long w[2000005], s[2000005];
deque<long long> dq1, dq2;
int main() {
  ios::sync_with_stdio(false);
  int n, p, d;
  cin >> n >> p >> d;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    w[i] += w[i - 1];
    if (i >= d)
      s[i] = w[i] - w[i - d];
    else
      s[i] = w[i];
  }
  int l = 1, r = 0, ans = d;
  dq1.push_back(0), dq2.push_back(0);
  while (l <= n) {
    while (!dq2.empty() && dq2.front() < l + d - 1)
      dq1.pop_front(), dq2.pop_front();
    while (r < n) {
      if (w[r + 1] - w[l - 1] - max(dq1.front(), s[r + 1]) > p) break;
      while (!dq1.empty() && s[r + 1] >= dq1.back())
        dq1.pop_back(), dq2.pop_back();
      r++;
      dq1.push_back(s[r]), dq2.push_back(r);
    }
    ans = max(ans, r - l + 1);
    l++;
  }
  cout << ans << endl;
  return 0;
}