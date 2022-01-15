#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
class DigitStringDiv2 {
 public:
  int count(string S, int X) {
    int len = S.length(), ans = 0;
    for (int i = 0; i < len; i++) {
      if (S[i] == '0') continue;
      for (int j = i; j < len; j++) {
        int num = 0;
        for (int k = i; k <= j; k++) {
          num *= 10;
          num += S[k] - '0';
        }
        if (num > X) ans++;
      }
    }
    return ans;
  }
};
