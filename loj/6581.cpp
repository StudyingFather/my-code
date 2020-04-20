#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int t[500005],vis[500005];
vector<int> e[500005],l,p[500005];
vector<pair<int,int> > res;
queue<int> q;
set<int> s;
void dfs(int u)
{
 vis[u]=1;
 s.insert(u);
 if(t[u]==1)
 {
  q.push(u);
  l.push_back(u);
 }
 for(auto v:e[u])
  if(!vis[v])
   dfs(v);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
  t[u]++,t[v]++;
 }
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   s.clear();
   l.clear();
   dfs(i);
   while(!q.empty())
   {
    int u=q.front();
    q.pop();
    s.erase(u);
    for(auto v:e[u])
    {
     t[v]--;
     if(t[v]==1)q.push(v);
    }
   }
   if(s.empty())
    for(auto u:l)
     res.push_back({u,e[u].front()});
   else
    for(auto u:s)
     for(auto v:e[u])
      if(!s.count(v))
       res.push_back({u,v});
  }
 sort(res.begin(),res.end());
 cout<<res.size()<<endl;
 for(auto p:res)
  cout<<p.first<<' '<<p.second<<endl;
 return 0;
}