// Problem: B. Update Files
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, tot = 1, ans = 0;
    cin >> n >> k;
    for (long long i = 1; i <= k && tot < n; i <<= 1) {
      tot += i, ans++;
    }
    if (tot < n) ans += (n - tot) / k + ((n - tot) % k != 0);
    cout << ans << endl;
  }
  return 0;
}