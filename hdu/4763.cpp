// Problem: Theme Section
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=4763
// Memory Limit: 32 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
#include <string>
using namespace std;
string s;
int pi[1000005];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    set<int> se;  // available length
    cin >> s;
    int l = s.length();
    for (int i = 1; i < l; i++) {
      int j = pi[i - 1];
      while (j > 0 && s[i] != s[j]) j = pi[j - 1];
      if (s[i] == s[j]) j++;
      pi[i] = j;
      if (i >= 2 * pi[i] - 1 && i + pi[i] + 1 >= l) se.insert(pi[i]);
    }
    int ans = pi[l - 1];
    while (ans > 0 && !se.count(ans)) ans = pi[ans - 1];
    cout << ans << endl;
  }
  return 0;
}