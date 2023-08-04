// Problem: P3375 【模板】KMP字符串匹配
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3375
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s, t;
int pi[2000005];
vector<int> res;
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  cin >> t;
  int tl = t.length();
  t.push_back('#');
  t += s;
  int l = t.length();
  for (int i = 1; i < l; i++) {
    int j = pi[i - 1];
    while (j > 0 && t[i] != t[j]) j = pi[j - 1];
    if (t[i] == t[j]) j++;
    pi[i] = j;
  }
  for (int i = tl + 1; i < l; i++)
    if (pi[i] == tl) res.push_back(i - 2 * tl + 1);
  for (auto x: res) cout << x << endl;
  for (int i = 0; i < tl; i++) cout << pi[i] << ' ';
  cout << endl;
  return 0;
}