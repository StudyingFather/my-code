// Problem: D - 756
// Contest: AtCoder - AtCoder Beginner Contest 114
// URL: https://atcoder.jp/contests/abc114/tasks/abc114_d
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
const int bound[] = {0, 2, 4, 14, 24, 74};
int t[105], cnt[15];
void calc(int x) {
  for (int i = 2; x != 1; i++)
    while (x % i == 0) x /= i, t[i]++;
}
int C(int x, int y) {
  if (x < y) return 0;
  if (y == 1) return x;
  if (y == 2) return x * (x - 1) / 2;
  return 0;
}
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) calc(i);
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= 5; j++)
      if (t[i] >= bound[j]) cnt[j]++;
  for (int i = 1; i <= 5; i++) cerr << cnt[i] << endl;
  ans += C(cnt[2], 2) * C(cnt[1] - 2, 1);  // 5 * 5 * 3
  ans += C(cnt[4], 1) * C(cnt[1] - 1, 1);  // 15 * 5
  ans += C(cnt[3], 1) * C(cnt[2] - 1, 1);  // 25 * 3
  ans += C(cnt[5], 1);                     // 75
  cout << ans << endl;
  return 0;
}