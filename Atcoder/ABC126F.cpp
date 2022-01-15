// Problem: F - XOR Matching
// Contest: AtCoder - AtCoder Beginner Contest 126
// URL: https://atcoder.jp/contests/abc126/tasks/abc126_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int m, k;
  cin >> m >> k;
  int maxx = (1 << m) - 1;
  if (k >= 1 << m)
    cout << -1 << endl;
  else if (m == 1 && k == 1) {
    cout << -1 << endl;
  } else if (m == 1 && k == 0) {
    cout << "0 0 1 1" << endl;
  } else {
    for (int i = 0; i <= maxx; i++)
      if (i != k) cout << i << ' ';
    cout << k << ' ';
    for (int i = maxx; i >= 0; i--)
      if (i != k) cout << i << ' ';
    cout << k << endl;
  }
  return 0;
}