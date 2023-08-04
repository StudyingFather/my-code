// Problem: E - Make it Palindrome
// Contest: AtCoder - Toyota Programming Contest 2023 Spring Qual B（AtCoder
// Beginner Contest 290） URL: https://atcoder.jp/contests/abc290/tasks/abc290_e
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v1[200005], v2[200005];
long long calc(int n, vector<int> &v1, vector<int> &v2) {
  long long ans = 0;
  int cnt = v1.size();
  for (auto x : v1) {
    ans += 1ll * x * (cnt - 1);
    cnt--;
  }
  cnt = v2.size();
  for (auto x : v2) {
    ans += 1ll * (n - x + 1) * (cnt - 1);
    cnt--;
  }
  int siz = v1.size(), pos = 0, maxp = v2.size() - 1;
  long long sum = 0;
  for (int i = 0; i < siz; i++) {
    while (pos <= maxp && v1[i] > (n - v2[pos] + 1)) {
      sum += (n - v2[pos] + 1);
      pos++;
    }
    ans += sum + 1ll * v1[i] * (maxp - pos + 1);
  }
  return ans;
}
long long full(int n) {
  vector<int> v1, v2;
  for (int i = 1; i <= n; i++) {
    if (i <= n / 2)
      v1.push_back(i);
    else
      v2.push_back(i);
  }
  reverse(v2.begin(), v2.end());
  return calc(n, v1, v2);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i <= n / 2)
      v1[x].push_back(i);
    else
      v2[x].push_back(i);
  }
  long long ans = full(n);
  for (int i = 1; i <= n; i++) {
    reverse(v2[i].begin(), v2[i].end());
    ans -= calc(n, v1[i], v2[i]);
  }
  cout << ans << endl;
  return 0;
}