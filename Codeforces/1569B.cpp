// Problem: B. Chess Tournament
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char res[55][55];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(res, 0, sizeof(res));
    vector<int> vec;
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        cnt++;
        vec.push_back(i);
      }
    }
    if (cnt == 1 || cnt == 2) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < cnt; i++) {
      res[vec[i]][vec[(i + 1) % cnt]] = '+';
      res[vec[(i + 1) % cnt]][vec[i]] = '-';
    }
    for (int i = 0; i < n; i++) res[i][i] = 'X';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (!res[i][j]) res[i][j] = '=';
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << res[i] << endl;
  }
  return 0;
}