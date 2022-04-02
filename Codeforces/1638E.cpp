// Problem: E. Colorful Operations
// Contest: Codeforces - Codeforces Round #771 (Div. 2)
// URL: https://codeforces.com/contest/1638/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct node {
  int l, r;
  mutable int c;
  node(int l, int r = -1, int c = 0) {
    this->l = l;
    this->r = r;
    this->c = c;
  }
  bool operator<(const node& a) const { return l < a.l; }
};
set<node> odt;
int n, q;
long long tag[1000005];
struct BIT {
  long long a[1000005];
  int n;
  void init(int n) { this->n = n; }
  int lowbit(int x) { return x & (-x); }
  void add(int p, long long x) {
    while (p <= n) {
      a[p] += x;
      p += lowbit(p);
    }
  }
  long long query(int p) {
    long long ans = 0;
    while (p) {
      ans += a[p];
      p -= lowbit(p);
    }
    return ans;
  }
} tr;
auto split(int pos) {
  auto it = odt.lower_bound(node(pos));
  if (it != odt.end() && it->l == pos) return it;
  it--;
  int l = it->l, r = it->r, c = it->c;
  odt.erase(it);
  odt.insert(node(l, pos - 1, c));
  return odt.insert(node(pos, r, c)).first;
}
void assign(int l, int r, int c) {
  auto itr = split(r + 1), itl = split(l);
  for (auto it = itl; it != itr; it++) {
    tr.add(it->l, tag[it->c]);
    tr.add(it->r + 1, -tag[it->c]);
  }
  odt.erase(itl, itr);
  odt.insert(node(l, r, c));
  tr.add(l, -tag[c]), tr.add(r + 1, tag[c]);
}
long long get_tag(int p) {
  auto it = odt.lower_bound(node(p));
  if (it != odt.end() && it->l == p) return tag[it->c];
  return tag[(--it)->c];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  odt.insert(node(1, n, 1));
  tr.init(n);
  while (q--) {
    string type;
    cin >> type;
    if (type == "Color") {
      int l, r, c;
      cin >> l >> r >> c;
      assign(l, r, c);
    } else if (type == "Add") {
      int c, x;
      cin >> c >> x;
      tag[c] += x;
    } else {
      int x;
      cin >> x;
      cout << tr.query(x) + get_tag(x) << endl;
    }
  }
  return 0;
}