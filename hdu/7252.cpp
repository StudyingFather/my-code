// Problem: Painting Game
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=7252
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 524 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = n / 7 * 3;
    n %= 7;
    if (s == "Alice") {
      if (n == 0)
        ans += 0;
      else if (n <= 3)
        ans += 1;
      else if (n <= 5)
        ans += 2;
      else
        ans += 3;
    } else if (s == "Bob") {
      if (n == 0)
        ans += 0;
      else if (n <= 2)
        ans += 1;
      else if (n <= 4)
        ans += 2;
      else
        ans += 3;
    }
    cout << ans << endl;
  }
  return 0;
}