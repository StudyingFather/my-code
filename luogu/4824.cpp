// Problem: P4824 [USACO15FEB] Censoring S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4824
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
using namespace std;
int nxt[1000005], pos[1000005];
int main() {
  string s, t, res;
  cin >> s >> t;
  int lt = t.length();
  for (int i = 1; i < lt; i++) {
    int j = nxt[i - 1];
    while (j > 0 && t[i] != t[j]) j = nxt[j - 1];
    j += (t[i] == t[j]);
    nxt[i] = j;
  }
  int cur = 0, tp = 0;
  for (auto c : s) {
    res.push_back(c), tp++;
    while (cur > 0 && t[cur] != c) cur = nxt[cur - 1];
    if (t[cur] == c) cur++;
    pos[tp - 1] = cur;
    if (cur == lt) {
      for (int i = 1; i <= lt; i++) res.pop_back(), tp--;
      cur = tp > 0 ? pos[tp - 1] : 0;
    }
  }
  cout << res << endl;
  return 0;
}