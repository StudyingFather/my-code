// Problem: A - camel Case
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA
// SYSTEMS） URL: https://atcoder.jp/contests/abc291/tasks/abc291_a Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.length();
  for (int i = 0; i < l; i++)
    if (s[i] >= 'A' && s[i] <= 'Z') {
      cout << i + 1 << endl;
      return 0;
    }
  return 0;
}