// Problem: A. Row GCD
// Contest: Codeforces - Codeforces Round #691 (Div. 1)
// URL: https://codeforces.com/contest/1458/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
long long a[200005], b[200005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  long long gcdnum = 0;
  for (int i = 2; i <= n; i++) gcdnum = gcd(gcdnum, a[i] - a[i - 1]);
  for (int i = 1; i <= m; i++) cout << gcd(gcdnum, a[1] + b[i]) << ' ';
  return 0;
}