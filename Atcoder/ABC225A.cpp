// Problem: A - Distinct Strings
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest
// 225) URL: https://atcoder.jp/contests/abc225/tasks/abc225_a Memory Limit:
// 1024 MB Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string str;
  cin >> str;
  sort(str.begin(), str.end());
  int cnt = 0;
  for (int i = 0; i < 2; i++) cnt += (str[i] != str[i + 1]);
  if (cnt == 0)
    cout << 1 << endl;
  else if (cnt == 1)
    cout << 3 << endl;
  else
    cout << 6 << endl;
  return 0;
}