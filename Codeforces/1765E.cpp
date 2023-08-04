// Problem: E. Exchange
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian
// Regional Contest (Online Mirror, ICPC Rules, Preferably Teams) URL:
// https://codeforces.com/contest/1765/problem/E Author : StudyingFather Site :
// https://studyingfather.com Memory Limit: 512 MB Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b)
      cout << 1 << endl;
    else
      cout << n / a + (n % a != 0) << endl;
  }
  return 0;
}