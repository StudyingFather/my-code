// Problem: Pancake Deque
// Contest: Google Coding Competitions - Round 1B 2022 - Code Jam 2022
// URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000acd59d
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main() {
  int T;
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n, maxd = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[l] <= a[r]) {
        ans += (a[l] >= maxd);
        maxd = max(a[l], maxd);
        l++;
      } else {
        ans += (a[r] >= maxd);
        maxd = max(a[r], maxd);
        r--;
      }
    }
    cout << "Case #" << kase << ": " << ans << endl;
  }
  return 0;
}