// Problem: E. Anya's Simultaneous Exhibition
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/contest/1779/problem/E
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int in[305], id[305], ans[305];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << '?' << ' ' << i << ' ';
    for (int j = 1; j <= n; j++) cout << (i == j ? 0 : 1);
    cout << endl;
    cin >> in[i];
    in[i] = n - 1 - in[i];
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [](int x, int y) { return in[x] < in[y]; });
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += in[id[i]];
    if (sum == i * (i - 1) / 2) {
      for (int j = 1; j <= i; j++) ans[id[j]] = 1;
      break;
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i];
  cout << endl;
  return 0;
}