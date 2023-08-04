// Problem: Hall of Fame
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/contest/1779/problem/A
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
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0, ans = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == 'L')
        cnt1++;
      else
        cnt2++;
    for (int i = 0; i + 1 < n; i++)
      if (s[i] == 'L' && s[i + 1] == 'R') ans = i;
    if (cnt1 == n || cnt2 == n)
      cout << -1 << endl;
    else
      cout << ans + 1 << endl;
  }
  return 0;
}