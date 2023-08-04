// Problem: D - Flip Cards
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA
// SYSTEMS） URL: https://atcoder.jp/contests/abc291/tasks/abc291_d Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int mod = 998244353;
int a[200005], b[200005];
long long f[200005][2];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  f[1][0] = f[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] != a[i]) f[i][0] += f[i - 1][0];
    if (a[i - 1] != b[i]) f[i][1] += f[i - 1][0];
    if (b[i - 1] != a[i]) f[i][0] += f[i - 1][1];
    if (b[i - 1] != b[i]) f[i][1] += f[i - 1][1];
    f[i][0] %= mod, f[i][1] %= mod;
  }
  cout << (f[n][0] + f[n][1]) % mod << endl;
  return 0;
}