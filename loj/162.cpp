// Problem: #162. 快速幂 2
// Contest: LibreOJ
// URL: https://loj.ac/p/162
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cmath>
#include <iostream>
using namespace std;
const int p = 998244352;
int a[5000005], x, n;
long long bs[32005], gs[32005];
int main() {
  ios::sync_with_stdio(false);
  cin >> x >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int sqrtp = ceil(sqrt(p));
  bs[0] = gs[0] = 1;
  for (int i = 1; i <= sqrtp; i++) bs[i] = bs[i - 1] * x % p;
  for (int i = 1; i <= sqrtp; i++) gs[i] = gs[i - 1] * bs[sqrtp] % p;
  for (int i = 1; i <= n; i++)
    cout << bs[a[i] % sqrtp] * gs[a[i] / sqrtp] % p << ' ';
  cout << endl;
  return 0;
}