// Problem: C. Min Max Sort
// Contest: Codeforces - Educational Codeforces Round 142 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1792/problem/C
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int a[200005], pos[200005];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    int l, r, ans = 0;
    if (n % 2) {
      l = r = pos[n / 2 + 1];
    } else {
      l = -1, r = -1;
    }
    for (int i = n / 2; i > 0; i--) {
      int cl = pos[i], cr = pos[n - i + 1];
      if (l == -1 && r == -1) {
        if (cl < cr)
          l = cl, r = cr;
        else {
          ans = i;
          break;
        }
      } else if (cl <= l && cr >= r && cl < cr) {
        l = cl, r = cr;
        continue;
      } else {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}