// Problem: Theramore
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7220
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 131 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int l = s.length();
    int o0 = 0, o1 = 0, e0 = 0, e1 = 0;
    for (int i = 0; i < l; i += 2) {
      if (s[i] == '0')
        e0++;
      else
        e1++;
    }
    for (int i = 1; i < l; i += 2) {
      if (s[i] == '0')
        o0++;
      else
        o1++;
    }
    for (int i = 0; i < l; i++) {
      if (i % 2 == 0) {
        if (e0)
          cout << 0, e0--;
        else
          cout << 1;
      } else {
        if (o0)
          cout << 0, o0--;
        else
          cout << 1;
      }
    }
    cout << endl;
  }
  return 0;
}