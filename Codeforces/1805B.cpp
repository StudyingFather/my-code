// Problem: B. The String Has a Target
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/B
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
    string s;
    cin >> s;
    int pos = 0;
    char minc = 127;
    for (int i = 0; i < n; i++) {
      if (s[i] <= minc) pos = i, minc = s[i];
    }
    cout << minc;
    for (int i = 0; i < n; i++)
      if (i != pos) cout << s[i];
    cout << endl;
  }
  return 0;
}