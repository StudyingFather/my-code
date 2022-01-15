#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long x;
    cin >> x;
    cout << (x == 1 ? "YES" : "NO") << endl;
  }
  return 0;
}