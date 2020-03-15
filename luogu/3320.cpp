#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
int head[100005],cnt;
int fa[100005][25],dfn[100005],id[100005];
long long dep[100005],dis[100005];
set<int> s;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int f,int w)
{
 dis[u]=dis[f]+w;
 dep[u]=dep[f]+1;
 fa[u][0]=f;
 dfn[u]=++cnt,id[cnt]=u;
 for(int i=1;i<=20;i++)
  fa[u][i]=fa[fa[u][i-1]][i-1];
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=f)dfs(v,u,e[i].w);
 }
}
int lca(int x,int y)
{
 if(dep[x]>dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[y]-dep[x]>=(1<<i))y=fa[y][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
   x=fa[x][i],y=fa[y][i];
 return fa[x][0];
}
long long dist(int x,int y)
{
 return dis[x]+dis[y]-2*dis[lca(x,y)];
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 long long ans=0;
 cin>>n>>m;
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 cnt=0;
 dfs(1,0,0);
 while(m--)
 {
  int x,f=-1;
  cin>>x;
  x=dfn[x];
  if(!s.count(x))
   s.insert(x),f=1;
  auto it=s.lower_bound(x);
  if(it==s.begin())it=--s.end();
  else it--;
  int y=id[*it];
  it=s.upper_bound(x);
  if(it==s.end())it=s.begin();
  int z=id[*it];
  if(f==-1)
   s.erase(x);
  x=id[x];
  long long d=dist(y,x)+dist(x,z)-dist(y,z);
  cout<<(ans+=d*f)<<endl;
 }
 return 0;
}