#include <cstring>
#include <iostream>
using namespace std;
const int n = 1000000;
int dfs(long long x) {
  if (x == 1) return 0;
  return dfs((x % 2) ? 3 * x + 1 : x / 2) + 1;
}
int main() {
  int ans = 0, maxd = 0;
  for (int i = 1; i <= n; i++) {
    int res = dfs(i);
    if (res > maxd) ans = i, maxd = res;
  }
  cout << ans << endl;
}