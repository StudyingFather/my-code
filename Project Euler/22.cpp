#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int main() {
  string str;
  while (cin >> str) v.push_back(str);
  sort(v.begin(), v.end());
  int cnt = 1;
  long long ans = 0;
  for (auto s : v) {
    int res = 0;
    for (auto c : s) res += c - 'A' + 1;
    ans += res * cnt;
    cnt++;
  }
  cout << ans << endl;
}