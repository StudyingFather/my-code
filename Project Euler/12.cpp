#include <iostream>
using namespace std;
int d(int x) {
  int res = 1;
  for (int i = 2; x != 1; i++) {
    int cnt = 0;
    while (x % i == 0) x /= i, cnt++;
    res *= (cnt + 1);
  }
  return res;
}
int main() {
  int n = 0;
  for (int i = 1;; i++) {
    n += i;
    if (d(n) >= 500) {
      cout << n << endl;
      return 0;
    }
  }
}