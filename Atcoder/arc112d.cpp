// Problem: D - Skate
// Contest: AtCoder - AtCoder Regular Contest 112
// URL: https://atcoder.jp/contests/arc112/tasks/arc112_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
#include <string>
using namespace std;
struct dsu {
  int fa[2005];
  void init(int n) {
    for (int i = 0; i < n; i++) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    fa[x] = y;
    return true;
  }
} ds;
string ma[1005];
bool vis[2005];
int main() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) cin >> ma[i];
  ds.init(h + w - 1);
  ds.merge(0, h);
  ds.merge(0, h + w - 1);
  ds.merge(h - 1, h);
  ds.merge(h - 1, h + w - 1);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (ma[i][j] == '#') ds.merge(i, h + j);
    }
  int cnt1 = 0, cnt2 = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < h; i++) {
    int x = ds.find(i);
    if (!vis[x]) cnt1++, vis[x] = true;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < w; i++) {
    int x = ds.find(h + i);
    if (!vis[x]) cnt2++, vis[x] = true;
  }
  cout << min(cnt1 - 1, cnt2 - 1) << endl;
  return 0;
}