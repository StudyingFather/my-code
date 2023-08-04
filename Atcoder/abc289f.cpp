// Problem: F - Teleporter Takahashi
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2023（AtCoder Beginner
// Contest 289） URL: https://atcoder.jp/contests/abc289/tasks/abc289_f Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstdlib>
#include <iostream>
using namespace std;
int sx, sy, tx, ty;
int a, b, c, d;
bool ans = true;
void move(int x, int y) {
  cout << x << ' ' << y << endl;
  sx = 2 * x - sx;
  sy = 2 * y - sy;
}
int main() {
  cin >> sx >> sy;
  cin >> tx >> ty;
  cin >> a >> b >> c >> d;
  if (sx % 2 != tx % 2 || sy % 2 != ty % 2) ans = false;
  if (a == b && c == d) {
    if ((tx == sx && ty == 2 * c - sy) || (tx == 2 * a - sx && ty == sy))
      ans = false;
  }
  if (a == b && tx != sx && tx != 2 * a - sx) ans = false;
  if (c == d && ty != sy && ty != 2 * c - sy) ans = false;
  if (!ans) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (a == b && sx != tx) move(a, c);
  if (c == d && sy != ty) move(a, c);
  while (sx < tx) move(a, c), move(a + 1, c);
  while (sx > tx) move(a + 1, c), move(a, c);
  while (sy < ty) move(a, c), move(a, c + 1);
  while (sy > ty) move(a, c + 1), move(a, c);
  return 0;
}