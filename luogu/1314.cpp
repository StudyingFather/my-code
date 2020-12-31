#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int w[200005], v[200005];
int l[200005], r[200005];
long long p1[200005], p2[200005];
int n, m;
long long s;
long long calc(int x) {
  memset(p1, 0, sizeof(p1));
  memset(p2, 0, sizeof(p2));
  for (int i = 1; i <= n; i++) {
    p1[i] = p1[i - 1] + (w[i] >= x);
    p2[i] = p2[i - 1] + (w[i] >= x) * v[i];
  }
  long long res = 0;
  for (int i = 1; i <= m; i++) {
    int cl = l[i], cr = r[i];
    res += (p1[cr] - p1[cl - 1]) * (p2[cr] - p2[cl - 1]);
  }
  return res;
}
int main() {
  cin >> n >> m >> s;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];
  int l = 1, r = 1000000;
  long long ans = 1e18;
  while (l <= r) {
    int mid = (l + r) >> 1;
    long long res = calc(mid);
    if (res < s)
      r = mid - 1;
    else
      l = mid + 1;
    ans = min(ans, abs(res - s));
  }
  cout << ans << endl;
  return 0;
}