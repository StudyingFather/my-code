// Problem: D. Journey
// Contest: Codeforces - Codeforces Beta Round 42 (Div. 2)
// URL: https://codeforces.com/contest/43/problem/D
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    if (m != 2) {
      cout << 1 << endl;
      cout << 1 << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
    } else
      cout << 0 << endl;
    for (int i = 1; i <= m; i++) cout << 1 << ' ' << i << endl;
    cout << 1 << ' ' << 1 << endl;
  } else if (m == 1) {
    if (n != 2) {
      cout << 1 << endl;
      cout << n << ' ' << 1 << ' ' << 1 << ' ' << 1 << endl;
    } else
      cout << 0 << endl;
    for (int i = 1; i <= n; i++) cout << i << ' ' << 1 << endl;
    cout << 1 << ' ' << 1 << endl;
  } else if (n % 2 == 0) {
    cout << 0 << endl;
    int dir = 1;
    bool fir = (m != 2);
    int x = 1, y = 1;
    while (true) {
      cout << x << ' ' << y << endl;
      if (x == n && y == 2) break;
      if ((y == 2 || y == m) && !fir) {
        x++;
        dir *= -1;
        if (m != 2) fir = true;
      } else {
        y += dir;
        if (x != 1 || y != 2) fir = false;
      }
    }
    for (int i = n; i >= 1; i--) cout << i << ' ' << 1 << endl;
  } else if (m % 2 == 0) {
    cout << 0 << endl;
    int dir = 1;
    bool fir = (n != 2);
    int x = 1, y = 1;
    while (true) {
      cout << x << ' ' << y << endl;
      if (x == 2 && y == m) break;
      if ((x == 2 || x == n) && !fir) {
        y++;
        dir *= -1;
        if (n != 2) fir = true;
      } else {
        x += dir;
        if (x != 2 || y != 1) fir = false;
      }
    }
    for (int i = m; i >= 1; i--) cout << 1 << ' ' << i << endl;
  } else {
    cout << 1 << endl;
    cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
    int dir = 1;
    bool fir = true;
    int x = 1, y = 1;
    while (true) {
      cout << x << ' ' << y << endl;
      if (x == n && y == m) break;
      if ((y == 1 || y == m) && !fir) {
        x++;
        dir *= -1;
        fir = true;
      } else {
        y += dir;
        fir = false;
      }
    }
    cout << 1 << ' ' << 1 << endl;
  }
  return 0;
}