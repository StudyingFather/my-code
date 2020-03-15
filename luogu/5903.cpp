#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned ui;
struct gen
{
 ui s;
 void init(ui seed)
 {
  s=seed;
 }
 ui next()
 {
  ui x=s;
  x^=x<<13;
  x^=x>>17;
  x^=x<<5;
  return s=x;
 }
}g;
int fa[5000005][25],dep[5000005],maxd[5000005],son[5000005],top[5000005];
vector<int> up[5000005],down[5000005];
vector<int> e[5000005];
void dfs1(int u,int f)
{
 dep[u]=maxd[u]=dep[f]+1;
 fa[u][0]=f;
 for(int k=1;k<=23;k++)
  fa[u][k]=fa[fa[u][k-1]][k-1];
 for(auto v:e[u])
 {
  dfs1(v,u);
  if(maxd[v]>maxd[son[u]])
   son[u]=v,maxd[u]=maxd[v];
 }
}
void dfs2(int u,int t)
{
 top[u]=t;
 if(u==t)
 {
  for(int i=0,p=u;i<=maxd[u]-dep[u];i++,p=fa[p][0])
   up[u].push_back(p);
  for(int i=0,p=u;i<=maxd[u]-dep[u];i++,p=son[p])
   down[u].push_back(p);
 }
 if(son[u])dfs2(son[u],t);
 for(auto v:e[u])
  if(v!=son[u])dfs2(v,v);
}
int get_kth(int x,int k)
{
 if(!k)return x;
 int t=log2(k);
 k-=1<<t,x=fa[x][t];
 k-=dep[x]-dep[top[x]],x=top[x];
 if(k>=0)return up[x][k];
 else return down[x][-k];
}
int main()
{
 int n,q,root;
 ui s;
 cin>>n>>q>>s;
 g.init(s);
 for(int i=1;i<=n;i++)
 {
  int f;
  cin>>f;
  if(f==0)root=i;
  else e[f].push_back(i);
 }
 dfs1(root,0);
 dfs2(root,root);
 long long ans=0,lastans=0;
 for(int i=1;i<=q;i++)
 {
  int x=(g.next()^lastans)%n+1,k=(g.next()^lastans)%dep[x];
  ans^=(i*(lastans=get_kth(x,k)));
 }
 cout<<ans<<endl;
 return 0;
}