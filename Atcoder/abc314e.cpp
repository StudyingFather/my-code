// Problem: E - Roulettes
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100;
const double inf = 1e300;
vector<int> v[maxn + 5];
int c[maxn + 5];
double f[maxn + 5], zerop[maxn + 5];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    int p, zerocnt = 0;
    scanf("%d", &p);
    for (int j = 1; j <= p; j++) {
      int s;
      scanf("%d", &s);
      v[i].push_back(s);
      if (s == 0) zerocnt++;
    }
    zerop[i] = 1.0 * zerocnt / p;
  }
  f[0] = 0;
  for (int i = 1; i <= m; i++) f[i] = inf;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      double res = c[j];
      int p = v[j].size();
      for (auto s : v[j]) {
        if (s == 0) continue;
        res += 1.0 * f[max(0, i - s)] / p;
      }
      res /= (1 - zerop[j]);
      f[i] = min(f[i], res);
    }
  }
  printf("%.9lf\n", f[m]);
  return 0;
}