// Problem: B - Star or Not
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest
// 225) URL: https://atcoder.jp/contests/abc225/tasks/abc225_b Memory Limit:
// 1024 MB Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int t[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    t[u]++, t[v]++;
  }
  bool flag = false;
  for (int i = 1; i <= n; i++) flag |= (t[i] == n - 1);
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}