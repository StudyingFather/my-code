// Problem: B - Call the ID Number
// Contest: AtCoder - AtCoder Beginner Contest 293
// URL: https://atcoder.jp/contests/abc293/tasks/abc293_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;
int vis[200005];
int main() {
  vector<int> res;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (!vis[i]) vis[x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) res.push_back(i);
  }
  cout << res.size() << endl;
  for (auto x : res) cout << x << ' ';
  cout << endl;
  return 0;
}