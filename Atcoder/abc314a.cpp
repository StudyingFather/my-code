// Problem: A - 3.14
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_a
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
using namespace std;
string s =
    "3."
    "14159265358979323846264338327950288419716939937510582097494459230781640628"
    "62089986280348253421170679";
int main() {
  int n;
  cin >> n;
  n += 2;
  for (int i = 0; i < n; i++) cout << s[i];
  cout << endl;
  return 0;
}