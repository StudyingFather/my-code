// Problem: C. Fault-tolerant Network
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1651/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
long long a[200005], b[200005];
int n;
long long twoline() {
  return min(abs(a[1] - b[1]) + abs(a[n] - b[n]),
             abs(a[1] - b[n]) + abs(a[n] - b[1]));
}
long long f1() {
  long long minc = abs(a[1] - b[1]);
  for (int i = 1; i <= n; i++) minc = min(minc, abs(a[1] - b[i]));
  return minc;
}
long long f2() {
  long long minc = abs(a[n] - b[1]);
  for (int i = 1; i <= n; i++) minc = min(minc, abs(a[n] - b[i]));
  return minc;
}
long long f3() {
  long long minc = abs(a[1] - b[1]);
  for (int i = 1; i <= n; i++) minc = min(minc, abs(a[i] - b[1]));
  return minc;
}
long long f4() {
  long long minc = abs(a[1] - b[n]);
  for (int i = 1; i <= n; i++) minc = min(minc, abs(a[i] - b[n]));
  return minc;
}
long long threeline() {
  long long m1 = abs(a[1] - b[1]);
  long long minc = m1 + f2() + f4();
  m1 = abs(a[1] - b[n]);
  minc = min(minc, m1 + f2() + f3());
  m1 = abs(a[n] - b[1]);
  minc = min(minc, m1 + f1() + f4());
  m1 = abs(a[n] - b[n]);
  minc = min(minc, m1 + f1() + f3());
  return minc;
}
long long fourline() { return f1() + f2() + f3() + f4(); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    long long minc = min(twoline(), min(threeline(), fourline()));
    cout << minc << endl;
  }
  return 0;
}