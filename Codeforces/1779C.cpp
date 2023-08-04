// Problem: Least Prefix Sum
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/contest/1779/problem/C
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <queue>
using namespace std;
long long a[200005];
int calc1(int start, int end) {
  priority_queue<long long, vector<long long>, greater<long long> > q;
  long long sum = 0;
  int ans = 0;
  for (int i = start; i <= end; i++) {
    sum += a[i];
    if (a[i] < 0) q.push(a[i]);
    while (sum < 0) {
      long long x = q.top();
      q.pop();
      ans++;
      sum -= 2 * x;
    }
  }
  return ans;
}
int calc2(int start, int end) {
  priority_queue<long long> q;
  long long sum = 0;
  int ans = 0;
  for (int i = start; i > end; i--) {
    sum -= a[i];
    if (a[i] > 0) q.push(a[i]);
    while (sum < 0) {
      long long x = q.top();
      q.pop();
      ans++;
      sum += 2 * x;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans += calc1(m + 1, n) + calc2(m, 1);
    cout << ans << '\n';
  }
  cout << endl;
  return 0;
}