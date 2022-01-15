#include <algorithm>
using namespace std;
class SpireAttack {
 public:
  int maxd = 0, n;
  int dealMostDamage(int N, vector<int> actions, vector<int> damage) {
    n = N;
    dfs(0, 0, 0, actions, damage);
    return maxd;
  }
  void dfs(int useda, int curp, int curd, vector<int> actions,
           vector<int> damage) {
    for (int i = curp; i < n; i++) {
      if (actions[i] + useda <= 3) {
        maxd = max(maxd, curd + damage[i]);
        dfs(useda + actions[i], i + 1, curd + damage[i], actions, damage);
      }
    }
  }
};
