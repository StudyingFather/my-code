// Problem: P9137 [THUPC 2023 初赛] 速战速决
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9137
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
#include <stack>
using namespace std;
int n;
int a[300005];
int ti[300005], tj[300005];
bool single_check() {
  bool ans = true;
  for (int i = 1; i <= n; i++) ans &= (ti[i] == 1);
  return ans;
}
void single_run() {
  if (n == 1) {
    cout << -1 << endl;
    return;
  }
  cout << n + 2 << endl;
  cout << a[n] << ' ';
  for (int i = 1; i < n; i++) {
    cout << a[i] << ' ';
  }
  int fc = (a[n] != 1) ? 1 : n;
  cout << fc << ' ' << fc << endl;
}
void normal_run() {
  set<int> sc, si, sj;
  stack<int> sta;
  cout << n << endl;
  int s = 0;
  for (int i = 1; i <= n; i++)
    if (tj[i] == 2) {
      s = i;
      sj.insert(i);
    } else if (ti[i] == 2)
      si.insert(i);
  cout << s << ' ';
  sj.erase(s), tj[s]--;
  sc.insert(s), sta.push(s);
  for (int i = 1; i < n; i++) {
    sta.push(a[i]), sc.insert(a[i]);
    if (si.count(a[i])) si.erase(a[i]);
    if (sc.count(a[i + 1])) {
      cout << s << ' ', tj[s]--;
      while (!sta.empty()) {
        int tp = sta.top();
        sta.pop(), sc.erase(tp);
        tj[tp]++;
        if (tj[tp] == 2) sj.insert(tp);
        if (tp == s) break;
      }
    } else if (sc.count(s)) {
      if (tj[a[i]]) {
        cout << a[i] << ' ';
        tj[a[i]] = 2;
        sj.insert(a[i]);
      } else if (!sj.empty()) {
        int x = *(--sj.end());
        cout << x << ' ', tj[x]--;
        sj.erase(x);
      } else {
        cout << s << ' ', tj[s]--;
        while (!sta.empty()) {
          int tp = sta.top();
          sta.pop(), sc.erase(tp);
          tj[tp]++;
          if (tj[tp] == 2) sj.insert(tp);
          if (tp == s) break;
        }
      }
    } else {
      cout << s << ' ', tj[s]--;
      sj.erase(s), sc.insert(s), sta.push(s);
    }
  }
  cout << endl;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ti[a[i]]++;
  }
  for (int i = 1; i <= n; i++) tj[i] = 2 - ti[i];
  if (single_check())
    single_run();
  else
    normal_run();
  return 0;
}