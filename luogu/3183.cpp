#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int f[100005],t[100005],ans;
vector<int> e[100005];
queue<int> q;
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  t[v]++;
 }
 for(int i=1;i<=n;i++)
  if(!t[i]&&e[i].size())q.push(i),f[i]=1;
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(auto v:e[u])
  {
   t[v]--;
   f[v]+=f[u];
   if(!t[v])q.push(v);
  }
 }
 for(int i=1;i<=n;i++)
  if(!e[i].size())ans+=f[i];
 cout<<ans<<endl;
 return 0;
}