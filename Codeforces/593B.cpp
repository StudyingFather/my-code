// Problem: B. Anton and Lines
// Contest: Codeforces - Codeforces Round #329 (Div. 2)
// URL: https://codeforces.com/contest/593/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef tuple<long long, long long, int> tlli;
vector<tlli> v1;
vector<tlli> v2;
int main() {
  int n;
  long long x1, x2;
  cin >> n;
  cin >> x1 >> x2;
  for (int i = 0; i < n; i++) {
    long long k, b;
    cin >> k >> b;
    v1.push_back(make_tuple(k * x1 + b, k * x2 + b, i));
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; i++)
    v2.push_back(make_tuple(get<1>(v1[i]), get<0>(v1[i]), get<2>(v1[i])));
  sort(v2.begin(), v2.end());
  bool ans = false;
  for (int i = 0; i < n; i++)
    if (get<2>(v1[i]) != get<2>(v2[i])) ans = true;
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}