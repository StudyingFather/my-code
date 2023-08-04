// Problem: Copy
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7152
// Memory Limit: 262 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bitset>
#include <iostream>
using namespace std;
const int maxn = 100000 + 5;
struct operation {
  int op;
  int l, r, x;
} o[maxn];
int a[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    bitset<maxn> f;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= q; i++) {
      cin >> o[i].op;
      if (o[i].op == 1)
        cin >> o[i].l >> o[i].r;
      else
        cin >> o[i].x;
    }
    for (int i = q; i; i--) {
      if (o[i].op == 2)
        f[o[i].x] = f[o[i].x] ^ 1;
      else {
        int l = o[i].l, r = o[i].r;
        bitset<maxn> low = f & (~bitset<maxn>(0) >> (maxn - r - 1));
        bitset<maxn> high = f & (~bitset<maxn>(0) << (r + 1));
        f = low ^ (high >> (r - l + 1));
      }
    }
    for (int i = 1; i <= n; i++) ans ^= f[i] * a[i];
    cout << ans << endl;
  }
  return 0;
}