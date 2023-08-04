// Problem: G - Triple Index
// Contest: AtCoder - AtCoder Beginner Contest 293
// URL: https://atcoder.jp/contests/abc293/tasks/abc293_g
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 200000;
struct query {
  int l, r, lid, rid, qid;
  bool operator<(const query& a) const {
    return lid < a.lid || (lid == a.lid && rid < a.rid);
  }
} b[maxn + 5];
int a[maxn + 5], t[maxn + 5];
long long ans[maxn + 5];
long long res;
long long C3(long long n) { return n * (n - 1) * (n - 2) / 6; }
void add(int c) {
  res -= C3(t[c]);
  t[c]++;
  res += C3(t[c]);
}
void del(int c) {
  res -= C3(t[c]);
  t[c]--;
  res += C3(t[c]);
}
int main() {
  int n, q;
  cin >> n >> q;
  int blocksiz = sqrt(n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) {
    cin >> b[i].l >> b[i].r;
    b[i].lid = b[i].l / blocksiz;
    b[i].rid = b[i].r / blocksiz;
    b[i].qid = i;
  }
  sort(b + 1, b + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    while (l > b[i].l) add(a[--l]);
    while (r < b[i].r) add(a[++r]);
    while (l < b[i].l) del(a[l++]);
    while (r > b[i].r) del(a[r--]);
    ans[b[i].qid] = res;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << endl;
  return 0;
}