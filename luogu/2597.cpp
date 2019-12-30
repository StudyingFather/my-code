#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> e[70005],e2[70005];
int fa[70005][25],f[70005],dep[70005],t[70005],siz[70005],n;
int lca(int x,int y)
{
 if(dep[x]>dep[y])swap(x,y);
 for(int i=16;i>=0;i--)
  if(dep[y]-dep[x]-(1<<i)>=0)y=fa[y][i];
 if(x==y)return x;
 for(int i=16;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   x=fa[x][i];
   y=fa[y][i];
  }
 return fa[x][0];
}
void bfs()
{
 queue<int> q;
 memset(f,-1,sizeof(f));
 for(int i=1;i<=n;i++)
  if(!t[i])q.push(i),f[i]=0;
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  e2[f[u]].push_back(u);
  dep[u]=dep[f[u]]+1;
  fa[u][0]=f[u];
  for(int i=1;i<=16;i++)
   fa[u][i]=fa[fa[u][i-1]][i-1];
  for(auto v:e[u])
  {
   if(f[v]==-1)f[v]=u;
   else f[v]=lca(f[v],u);
   t[v]--;
   if(!t[v])q.push(v);
  }
 }
}
void dfs(int u)
{
 siz[u]=1;
 for(auto v:e2[u])
  dfs(v),siz[u]+=siz[v];
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int v;
  while(cin>>v)
   if(!v)break;
   else e[v].push_back(i),t[i]++;
 }
 bfs();
 dfs(0);
 for(int i=1;i<=n;i++)
  cout<<siz[i]-1<<endl;
 return 0;
}