// Problem: B. Subtract Operation
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    set<int> se;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      se.insert(x);
    }
    bool ans = false;
    for (auto x : se) ans |= se.count(x + k);
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}