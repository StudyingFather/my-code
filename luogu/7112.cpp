// Problem: P7112 【模板】行列式求值
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7112
// Memory Limit: 64 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
long long a[605][605];
int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  long long det = 1;
  for (int i = 1; i <= n; i++) {
    bool flag = false;
    for (int j = i; j <= n; j++) {
      if (a[j][i] != 0) {
        flag = true;
        swap(a[i], a[j]);
        if (i != j) det = p - det;
      }
    }
    if (!flag) {
      det = 0;
      break;
    }
    for (int j = i + 1; j <= n; j++) {
      while (a[j][i]) {
        if (a[i][i] > a[j][i]) swap(a[i], a[j]), det = p - det;
        int t = a[j][i] / a[i][i];
        for (int k = i; k <= n; k++) {
          a[j][k] = ((a[j][k] - t * a[i][k]) % p + p) % p;
        }
      }
    }
    det = det * a[i][i] % p;
  }
  cout << det << endl;
  return 0;
}