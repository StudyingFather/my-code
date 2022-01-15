#include <iostream>
using namespace std;
int h[305];
int main() {
  int n, m, l;
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      h[x]++;
    }
  for (int i = 0; i < l; i++) cout << h[i] << ' ';
  cout << endl;
  return 0;
}