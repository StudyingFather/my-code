// Problem: E. Rescheduling the Exam
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
using namespace std;
int n, d;
set<int> se;
bool trial(int s, int x) {
  int t = 0, lasta = 0;
  se.erase(s);
  lasta = 0;
  for (auto a : se) {
    if (a - lasta >= 2 * x + 2) {
      t = lasta + x + 1;
      break;
    }
    lasta = a;
  }
  if (t == 0) {
    if (lasta + x + 1 <= d)
      t = d;
    else {
      se.insert(s);
      return false;
    }
  }
  se.insert(t);
  bool res = true;
  lasta = 0;
  for (auto a : se) {
    if (a - lasta - 1 < x) {
      res = false;
      break;
    }
    lasta = a;
  }
  se.erase(t), se.insert(s);
  return res;
}
bool check(int x) {
  int lasta = *se.begin(), s1 = 0, s2 = 0;
  for (auto a : se) {
    if (a == *se.begin()) {
      if (a <= x) {
        s1 = s2 = a;
        break;
      }
    } else if (a - lasta - 1 < x) {
      s1 = lasta, s2 = a;
      break;
    }
    lasta = a;
  }
  if (s1 == 0) return true;
  return trial(s1, x) || trial(s2, x);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    se.clear();
    cin >> n >> d;
    // se.insert(0);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      se.insert(x);
    }
    int l = 0, r = d, ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    cout << ans << endl;
  }
  return 0;
}