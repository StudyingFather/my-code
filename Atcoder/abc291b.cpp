// Problem: B - Trimmed Mean
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA
// SYSTEMS） URL: https://atcoder.jp/contests/abc291/tasks/abc291_b Author :
// StudyingFather Site : https://studyingfather.com Memory Limit: 1024 MB Time
// Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cstdio>
using namespace std;
int a[505];
int main() {
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= 5 * n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 5 * n + 1);
  for (int i = n + 1; i <= 4 * n; i++) sum += a[i];
  printf("%.9lf\n", sum * 1.0 / n / 3);
  return 0;
}