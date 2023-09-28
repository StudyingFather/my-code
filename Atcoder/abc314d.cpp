// Problem: D - LOWER
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
const int maxn = 500000;
char s[maxn + 5];
int lastst[maxn + 5];
char toLower(char c) {
  if (c >= 'a' && c <= 'z') return c;
  return c - 'A' + 'a';
}
char toUpper(char c) {
  if (c >= 'A' && c <= 'Z') return c;
  return c - 'a' + 'A';
}
int main() {
  int n, q;
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &q);
  int lasttt = 0, sta = -1;
  for (int i = 1; i <= q; i++) {
    int t, x;
    char c;
    scanf("%d %d %c", &t, &x, &c);
    x--;
    if (t == 1) {
      s[x] = c;
      lastst[x] = i;
    } else if (t == 2) {
      sta = 0;
      lasttt = i;
    } else {
      sta = 1;
      lasttt = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (sta == -1)
      putchar(s[i]);
    else if (sta == 0) {
      if (lastst[i] > lasttt)
        putchar(s[i]);
      else
        putchar(toLower(s[i]));
    } else {
      if (lastst[i] > lasttt)
        putchar(s[i]);
      else
        putchar(toUpper(s[i]));
    }
  }
  puts("");
  return 0;
}