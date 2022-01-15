#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
class MarsHabitats {
 public:
  vector<int> design(vector<int> distances) {
    vector<int> res;
    vector<pii> edge[205];
    vector<pii> nd;
    int n = distances.size();
    if (n % 2 == 1)
      return res;  // no solution
    else {
      for (int i = 0; i < n; i++) nd.emplace_back(distances[i], i);
      sort(nd.begin(), nd.end());
      for (int i = 1; i < n; i++) {
        int u = nd[i - 1].second, v = nd[i].second,
            w = nd[i].first - nd[i - 1].first;
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
        if (i % 2 == 0) {
          edge[u].emplace_back(v, w);
          edge[v].emplace_back(u, w);
        }
      }
      edge[0].emplace_back(0, 0);
      edge[0].emplace_back(0, 0);
      edge[nd[n - 1].second].emplace_back(nd[n - 1].second, 0);
      edge[nd[n - 1].second].emplace_back(nd[n - 1].second, 0);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
          res.push_back(edge[i][j].first);
          res.push_back(edge[i][j].second);
        }
      }
      return res;
    }
  }
};