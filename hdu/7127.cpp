#include <cmath>
#include <iostream>
using namespace std;
long long a, b, c;
long long f(long long x) { return a * x * x + b * x + c; }
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    long long x0, x1, y0, y1, y2;
    cin >> x0 >> x1 >> y0 >> y1 >> y2;
    long long fx0 = f(x0);
    long long fx1 = f(x1);
    if (fx1 > y2)
      cout << "No" << endl;
    else if (fx0 == y0 || fx1 == y0)
      cout << "No" << endl;
    else {
      long double topx = (long double)(-b) / (2 * a);
      if (fx0 <= y0)
        cout << "No" << endl;
      else if (topx <= x1) {
        if (fx1 < y0)
          cout << "Yes" << endl;
        else {
          int x2 = x1 + (x1 - x0);
          long long fx2 = f(x2);
          if (fx2 < y0)
            cout << "Yes" << endl;
          else
            cout << "No" << endl;
        }
      }
    }
  }
  return 0;
}