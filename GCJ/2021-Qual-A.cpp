// Problem: Reversort
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam
// 2021 URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// Author: StudyingFather
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int l[105];
int main() {
  int T;
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    int cost = 0;
    for (int i = 1; i < n; i++) {
      int r = i;
      for (int j = i; j <= n; j++)
        if (l[j] < l[r]) r = j;
      reverse(l + i, l + r + 1);
      cost += r - i + 1;
    }
    cout << "Case #" << kase << ": " << cost << endl;
  }
  return 0;
}