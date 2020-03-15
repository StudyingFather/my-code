#include <iostream>
#include <vector>
#include <set>
using namespace std;
int w[200005];
multiset<int> s[200005];
vector<int> e[200005];
void merge(int x,int y)
{
 if(s[x].size()<s[y].size())swap(s[x],s[y]);
 for(auto p:s[y])
  s[x].insert(p);
}
void dfs(int u)
{
 for(auto v:e[u])
 {
  dfs(v);
  merge(u,v);
 }
 s[u].insert(w[u]);
 auto it=s[u].lower_bound(w[u]);
 if(it!=s[u].begin())s[u].erase(--it);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>w[i];
 for(int i=2;i<=n;i++)
 {
  int f;
  cin>>f;
  e[f].push_back(i);
 }
 dfs(1);
 cout<<s[1].size()<<endl;
 return 0;
}