// Problem: A. Typical Interview Problem
// Contest: Codeforces - Educational Codeforces Round 144 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1796/problem/A
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const string bfstring = "FBFFBFFBFBFFBFFBFBFFBFFB";  // 3 5 6 9 10 12 15
bool check(string s, int ind) {
  int l = s.length();
  for (int i = 0; i < l; i++) {
    if (s[i] != bfstring[ind + i]) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    bool ans = false;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < 8; i++) ans |= check(s, i);
    cout << (ans ? "YES" : "NO") << endl;
  }
}