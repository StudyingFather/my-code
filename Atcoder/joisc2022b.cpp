// Problem: B - 京都観光 (Sightseeing in Kyoto)
// Contest: AtCoder - JOI 2021/2022 春合宿 過去問
// URL: https://atcoder.jp/contests/joisc2022/tasks/joisc2022_b
// Author : StudyingFather
// Site : https://studyingfather.com
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;
struct seg {
  int type;
  int l, r;
  double k;
  seg(int type, int l, int r, double k) {
    this->type = type;
    this->l = l;
    this->r = r;
    this->k = k;
  }
  bool operator<(const seg& a) const {
    return k < a.k ||
           (k == a.k && (type < a.type || (type == a.type && l < a.l)));
  }
};
int a[100005], b[100005];
set<seg> s;
set<int> ra, rb;
int main() {
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  for (int i = 1; i <= h; i++) cin >> a[i];
  for (int i = 1; i <= w; i++) cin >> b[i];
  for (int i = 2; i <= h; i++) {
    s.insert(seg(0, i - 1, i, a[i] - a[i - 1]));
    ra.insert(i);
  }
  s.insert(seg(0, 0, 1, -1e20));
  ra.insert(1);
  for (int i = 2; i <= w; i++) {
    s.insert(seg(1, i - 1, i, b[i] - b[i - 1]));
    rb.insert(i);
  }
  s.insert(seg(1, 0, 1, -1e20));
  rb.insert(1);
  int cnta = h, cntb = w, x = h, y = w;
  long long ans = 0;
  while (cnta > 1 || cntb > 1) {
    auto it = --s.end();
    if (it->type == 0) {
      if (it->r == x) {
        ans += 1ll * (it->r - it->l) * b[y];
        x = it->l;
        ra.erase(it->r);
        s.erase(it);
      } else {
        int l = it->l, r = it->r, nr = *ra.upper_bound(it->r);
        ra.erase(r);
        s.erase(seg(0, l, r, 1.0 * (a[r] - a[l]) / (r - l)));
        s.erase(seg(0, r, nr, 1.0 * (a[nr] - a[r]) / (nr - r)));
        s.insert(seg(0, l, nr, 1.0 * (a[nr] - a[l]) / (nr - l)));
      }
      cnta--;
    } else {
      if (it->r == y) {
        ans += 1ll * (it->r - it->l) * a[x];
        y = it->l;
        rb.erase(it->r);
        s.erase(it);
      } else {
        int l = it->l, r = it->r, nr = *rb.upper_bound(it->r);
        rb.erase(r);
        s.erase(seg(1, l, r, 1.0 * (b[r] - b[l]) / (r - l)));
        s.erase(seg(1, r, nr, 1.0 * (b[nr] - b[r]) / (nr - r)));
        s.insert(seg(1, l, nr, 1.0 * (b[nr] - b[l]) / (nr - l)));
      }
      cntb--;
    }
  }
  cout << ans << endl;
  return 0;
}