// Problem: C. Banknotes
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[15];
long long pow10(int x) {
  long long ans = 1;
  for (int i = 1; i <= x; i++) ans *= 10;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    a[n + 1] = 18;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      int x = min((long long)k + 1, pow10(a[i + 1] - a[i]) - 1);
      ans += x * pow10(a[i]);
      k -= x;
    }
    cout << ans << endl;
  }
  return 0;
}