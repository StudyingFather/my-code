#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int vis[200005],p[200005],q[200005];
vector<int> e[200005];
void dfs(int u,int c)
{
 vis[u]=c;
 for(auto v:e[u])
  if(vis[v]==-1)dfs(v,c^1);
}
int main()
{
 memset(vis,-1,sizeof(vis));
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x,y;
  cin>>x>>y;
  if(p[x])
  {
   e[i].push_back(p[x]);
   e[p[x]].push_back(i);
   p[x]=0;
  }
  else p[x]=i;
  if(q[y])
  {
   e[i].push_back(q[y]);
   e[q[y]].push_back(i);
   q[y]=0;
  }
  else q[y]=i;
 }
 for(int i=1;i<=n;i++)
  if(vis[i]==-1)dfs(i,0);
 for(int i=1;i<=n;i++)
  cout<<(vis[i]?'r':'b');
 return 0;
}