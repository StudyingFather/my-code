// Problem: E - Geometric Progression
// Contest: AtCoder - AtCoder Beginner Contest 293
// URL: https://atcoder.jp/contests/abc293/tasks/abc293_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
using namespace std;
const int siz = 2;
long long a, x, m;
struct mat {
  long long a[siz][siz];
  mat(bool iden = false) {
    memset(a, 0, sizeof(a));
    if (iden) {
      for (int i = 0; i < siz; i++) a[i][i] = 1;
    }
  }
  mat operator*(const mat& b) const {
    mat res;
    for (int k = 0; k < siz; k++)
      for (int i = 0; i < siz; i++)
        for (int j = 0; j < siz; j++)
          res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % m;
    return res;
  }
};
mat fpow(mat x, long long y) {
  mat ans(true);
  while (y) {
    if (y & 1) ans = ans * x;
    x = x * x;
    y >>= 1;
  }
  return ans;
}
int main() {
  cin >> a >> x >> m;
  mat base, mul;
  base.a[0][0] = base.a[0][1] = 1;
  mul.a[0][0] = a, mul.a[1][0] = mul.a[1][1] = 1;
  cout << (base * fpow(mul, x - 1)).a[0][0] << endl;
  return 0;
}