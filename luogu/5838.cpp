#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int col[100005];
int siz[100005],fa[100005],son[100005],top[100005],dep[100005],id[100005],cnt;
vector<int> e[100005],c[100005];
void dfs1(int u,int f)
{
 siz[u]=1;
 fa[u]=f;
 dep[u]=dep[f]+1;
 for(auto v:e[u])
  if(v!=f)
  {
   dfs1(v,u);
   siz[u]+=siz[v];
   if(siz[v]>siz[son[u]])son[u]=v;
  }
}
void dfs2(int u,int t)
{
 top[u]=t;
 id[u]=++cnt;
 c[col[u]].push_back(cnt);
 if(!son[u])return;
 dfs2(son[u],t);
 for(auto v:e[u])
  if(v!=fa[u]&&v!=son[u])
   dfs2(v,v);
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>col[i];
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs1(1,0);
 dfs2(1,1);
 while(m--)
 {
  int u,v,w;
  int ans=0;
  cin>>u>>v>>w;
  while(top[u]!=top[v])
  {
   if(dep[top[u]]>dep[top[v]])swap(u,v);
   auto p=lower_bound(c[w].begin(),c[w].end(),id[top[v]]);
   if(p!=c[w].end()&&*p<=id[v])ans=1;
   v=fa[top[v]];
  }
  if(dep[u]>dep[v])swap(u,v);
  auto p=lower_bound(c[w].begin(),c[w].end(),id[u]);
   if(p!=c[w].end()&&*p<=id[v])ans=1;
  cout<<ans;
 }
 return 0;
}