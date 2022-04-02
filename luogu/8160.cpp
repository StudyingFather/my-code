// Problem: P8160 [JOI 2022 Final] 星际蛋糕 (Intercastellar)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8160
// Memory Limit: 537 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[200005];
long long b[200005];
int lowbit(int x) { return x & (-x); }
int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = lowbit(a[i]);
    a[i] /= b[i];
    cerr << a[i] << ' ';
    b[i] += b[i - 1];
  }
  cin >> q;
  int pos = 1;
  for (int i = 1; i <= q; i++) {
    long long x;
    cin >> x;
    while (pos <= n && b[pos] < x) pos++;
    cout << a[pos] << endl;
  }
  return 0;
}