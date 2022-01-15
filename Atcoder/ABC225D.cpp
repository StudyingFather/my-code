// Problem: D - Play Train
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest
// 225) URL: https://atcoder.jp/contests/abc225/tasks/abc225_d Memory Limit:
// 1024 MB Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
  int pre, next;
} l[100005];
void connect(int x, int y) {
  l[y].pre = x;
  l[x].next = y;
}
void disconnect(int x, int y) {
  l[y].pre = 0;
  l[x].next = 0;
}
int main() {
  int n, q;
  cin >> n >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      connect(x, y);
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      disconnect(x, y);
    } else {
      int x;
      cin >> x;
      vector<int> respre, respost;
      int cur = x;
      while (cur) {
        cur = l[cur].pre;
        if (cur) respre.push_back(cur);
      }
      cur = x;
      while (cur) {
        cur = l[cur].next;
        if (cur) respost.push_back(cur);
      }
      reverse(respre.begin(), respre.end());
      cout << respre.size() + respost.size() + 1 << ' ';
      for (auto id : respre) cout << id << ' ';
      cout << x << ' ';
      for (auto id : respost) cout << id << ' ';
      cout << endl;
    }
  }
  return 0;
}