// Problem: MKnez's ConstructiveForces Task
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/contest/1779/problem/B
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    if (n % 2 == 0) {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) cout << (i % 2 == 1 ? 1 : -1) << ' ';
      cout << endl;
    } else {
      if (n == 3) {
        cout << "NO" << endl;
        continue;
      }
      cout << "YES" << endl;
      int x = n / 2 - 1;
      for (int i = 1; i <= n; i++)
        if (i % 2)
          cout << x << ' ';
        else
          cout << -x - 1 << ' ';
      cout << endl;
    }
  }
  return 0;
}