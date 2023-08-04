// Problem: Arithmetic Subsequence
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7233
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 524 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
struct number {
  int a0, a;
} a[5005], b[5005];
int aa[5005];
int n;
bool checkNoSolution() {
  for (int i = 1; i <= n; i++) aa[i] = a[i].a0;
  sort(aa + 1, aa + n + 1);
  for (int i = 1; i <= n; i++)
    if (aa[i - 1] == aa[i] && aa[i] == aa[i + 1]) return true;
  return false;
}
void divide(int l, int r) {
  if (l >= r) return;
  int po = l - 1, pe = r + 1;
  bool flag = false;
  for (int i = l; i <= r; i++) {
    if (a[i].a != 0) flag = true;
    if (a[i].a % 2)
      b[++po] = a[i], b[po].a--;
    else
      b[--pe] = a[i], b[pe].a /= 2;
  }
  if (!flag) return;
  for (int i = l; i <= r; i++) a[i] = b[i];
  divide(l, po);
  divide(pe, r);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].a0, a[i].a = a[i].a0;
    if (checkNoSolution()) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    divide(1, n);
    for (int i = 1; i <= n; i++) cout << a[i].a0 << ' ';
    cout << endl;
  }
  return 0;
}