// Problem: B - Roulette
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 100;
const int maxc = 37;
int c[maxn + 5];
vector<int> b[maxc + 5];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 1; j <= c[i]; j++) {
      int x;
      cin >> x;
      b[x].push_back(i);
    }
  }
  int x, minc = maxc + 5, k = 0;
  cin >> x;
  for (auto id : b[x]) {
    if (c[id] < minc)
      minc = c[id], k = 1;
    else if (c[id] == minc)
      k++;
  }
  cout << k << endl;
  set<int> output;
  for (auto id : b[x])
    if (c[id] == minc) output.insert(id);
  for (auto id : output) cout << id << ' ';
  cout << endl;
}