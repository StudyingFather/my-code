#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> pii;
const int n = 1000;
int main() {
  int maxl = 0, ans = 0;
  for (int i = 2; i <= n; i++) {
    map<pii, int> ma;
    int r = 10, pos = 1;
    while (true) {
      if (ma[pii(r / i, r % i)] != 0) {
        int len = pos - ma[pii(r / i, r % i)];
        if (len > maxl) ans = i, maxl = len;
        break;
      }
      ma[pii(r / i, r % i)] = pos;
      r %= i, r *= 10;
      pos++;
    }
  }
  cout << ans << endl;
}