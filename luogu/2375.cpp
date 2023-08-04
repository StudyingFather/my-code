// Problem: P2375 [NOI2014] 动物园
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2375
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstring>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int nxt[1000005], f[1000005];
int main() {
  int n;
  cin >> n;
  while (n--) {
    memset(f, 0, sizeof(f));
    string s;
    cin >> s;
    int l = s.length();
    f[0] = 1;
    for (int i = 1; i < l; i++) {
      int j = nxt[i - 1];
      while (j > 0 && s[i] != s[j]) j = nxt[j - 1];
      j += (s[i] == s[j]);
      nxt[i] = j;
      if (j)
        f[i] = f[j - 1] + 1;
      else
        f[i] = 1;
    }
    long long ans = 1;
    int j = 0;
    for (int i = 1; i < l; i++) {
      while (j > 0 && s[i] != s[j]) j = nxt[j - 1];
      j += (s[i] == s[j]);
      while (j * 2 > i + 1) j = nxt[j - 1];
      if (j > 0) ans = ans * (f[j - 1] + 1) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}