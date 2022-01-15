#include <iostream>
using namespace std;
const int n = 10000;
long long d[n + 5];
int main() {
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (i % j == 0) d[i] += j;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (d[i] == j && d[j] == i) ans += i + j;
  cout << ans << endl;
}