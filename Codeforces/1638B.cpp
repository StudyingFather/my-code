// Problem: B. Odd Swap Sort
// Contest: Codeforces - Codeforces Round #771 (Div. 2)
// URL: https://codeforces.com/contest/1638/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int a[100005];
set<int> s0, s1;
int main() {
  int t;
  cin >> t;
  while (t--) {
    s0.clear(), s1.clear();
    int n;
    bool ans = true;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i; i--) {
      if (a[i] % 2 == 1) {
        if (!s1.empty() && *s1.begin() < a[i]) ans = false;
        s1.insert(a[i]);
      } else {
        if (!s0.empty() && *s0.begin() < a[i]) ans = false;
        s0.insert(a[i]);
      }
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}