// Problem: D. K-good
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
long long min_prime_factor(long long x) {
  for (long long i = 3; i * i <= x; i += 2)
    if (x % i == 0) return i;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2)
      cout << 2 << endl;
    else {
      long long p2 = 1;
      while (n % 2 == 0) n /= 2, p2 *= 2;
      if (n == 1)
        cout << -1 << endl;
      else if (n >= 2 * p2 + 1)
        cout << p2 * 2 << endl;
      else
        cout << n << endl;
    }
  }
  return 0;
}