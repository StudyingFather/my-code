// Problem : P3648 [APIO2014]序列分割
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3648
// Memory Limit : 500 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int q[100005], pre[100005][205];
long long s[100005], f[100005], g[100005];
stack<int> res;
double slope(int x, int y) {
  if (s[x] == s[y]) return -1e18;
  return 1.0 * (g[x] - g[y] - s[x] * s[x] + s[y] * s[y]) / (s[y] - s[x]);
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] += s[i - 1];
  }
  for (int t = 1; t <= k; t++) {
    memset(q, 0, sizeof(q));
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
      while (l < r && slope(q[l], q[l + 1]) <= s[i]) l++;
      f[i] = g[q[l]] + s[q[l]] * (s[i] - s[q[l]]);
      pre[i][t] = q[l];
      while (l < r && slope(q[r - 1], q[r]) >= slope(q[r], i)) r--;
      q[++r] = i;
    }
    memcpy(g, f, sizeof(f));
  }
  cout << f[n] << endl;
  int p = n;
  while (k) {
    p = pre[p][k];
    res.push(p);
    k--;
  }
  while (!res.empty()) {
    cout << res.top() << ' ';
    res.pop();
  }
  return 0;
}