// Problem: D. Watch the Videos
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian
// Regional Contest (Online Mirror, ICPC Rules, Preferably Teams) URL:
// https://codeforces.com/contest/1765/problem/D Author : StudyingFather Site :
// https://studyingfather.com Memory Limit: 512 MB Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
using namespace std;
typedef long long i64;
multiset<i64> se;
int main() {
  int n, m;
  cin >> n >> m;
  i64 ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    se.insert(x);
    ans += x + 1;
  }
  int lastx = 0;
  for (int i = 1; i <= n; i++) {
    auto it = se.upper_bound(m - lastx);
    if (it == se.begin()) {
      it = --se.end();
    } else
      it--;
    if (*it + lastx <= m) {
      if (i != 1) ans--;
    }
    lastx = *it;
    se.erase(it);
  }
  cout << ans << endl;
  return 0;
}