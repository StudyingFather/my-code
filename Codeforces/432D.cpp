// Problem: D. Prefixes and Suffixes
// Contest: Codeforces - Codeforces Round #246 (Div. 2)
// URL: https://codeforces.com/problemset/problem/432/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
#include <set>
using namespace std;
string s;
set<int> se;
int pi[100005], res[100005];
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int l = s.length();
  for (int i = 1; i < l; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  int p = l;
  while (p > 0) se.insert(p), p = pi[p - 1];
  for (int i = l; i; i--) {
    res[i]++;
    res[pi[i - 1]] += res[i];
  }
  cout << se.size() << endl;
  for (auto x: se)
    cout << x << ' ' << res[x] << endl;
  return 0;
}