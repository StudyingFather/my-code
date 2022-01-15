// Problem: A. AB Balance
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int len = str.length();
    if (str[0] == str[len - 1])
      cout << str << endl;
    else {
      str[len - 1] = str[0];
      cout << str << endl;
    }
  }
  return 0;
}