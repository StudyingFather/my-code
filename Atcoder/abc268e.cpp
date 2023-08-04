// Problem: E - Chinese Restaurant (Three-Star Version)
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022 Summer
// (AtCoder Beginner Contest 268)
// URL: https://atcoder.jp/contests/abc268/tasks/abc268_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int t[500005];
queue<int> q1, q2;
int main() {
  int n;
  cin >> n;
  int maxd = n / 2, sig = n % 2;
  long long sum = 0, cnt1 = 0, cnt2 = 0, ans = 1ll << 60;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    int d = p - i;
    if (d > maxd || (d == maxd && !sig)) {
      d -= n;
    } else if (-d > maxd) {
      d += n;
    }
    if (d < 0)
      cnt1++;
    else
      cnt2++;
    sum += abs(d);
    t[d + maxd]++;
  }
  ans = sum;
  for (int i = 0; i < maxd; i++) q1.push(t[i]);
  for (int i = maxd; i < n; i++) q2.push(t[i]);
  for (int i = 1; i < n; i++) {
    int q1f = q1.front(), q2f = q2.front();
    sum += (cnt1 - q1f) - (cnt2 - q2f);
    sum += q2f, cnt1 += q2f, cnt2 -= q2f;
    q1.push(q2f), q2.pop();
    if (!sig) sum -= q1f;
    cnt1 -= q1f, cnt2 += q1f;
    q2.push(q1f), q1.pop();
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}