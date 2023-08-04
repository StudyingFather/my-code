// Problem: A. We Need the Zero
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/0
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int xsum = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      xsum ^= x;
    }
    if (n % 2)
      cout << xsum << endl;
    else
      cout << (xsum == 0 ? 0 : -1) << endl;
  }
  return 0;
}