// Problem: P3370 【模板】字符串哈希
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3370
// Memory Limit: 125 MB
// Time Limit: 500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
#include <cstring>
#define MOD 100000000 + 7
long long h[10005];
int cnt;
char s[1505];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    memset(s, 0, sizeof(s));
    scanf("%s", s);
    long long hr = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) hr = (hr * 127 + s[i]) % MOD;
    int flag = 1;
    for (int i = 1; i <= cnt; i++)
      if (hr == h[i]) {
        flag = 0;
        break;
      }
    if (flag) h[++cnt] = hr;
  }
  printf("%d", cnt);
  return 0;
}