// Problem: A. Playoff
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1651/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
  }
  return 0;
}