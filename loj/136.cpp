#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
 bool operator<(const edge&a)const
 {
  return w<a.w;
 }
}ed[100005];
struct graph
{
 struct edge
 {
  int v,w,next;
 }e[200005];
 int head[100005],cnt;
 void addedge(int u,int v,int w)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 int fa[100005][25],dis[100005][25],vis[100005],dep[100005];
 bool visit(int x)
 {
  return vis[x];
 }
 void dfs(int u,int f)
 {
  vis[u]=1;
  dep[u]=dep[f]+1;
  fa[u][0]=f;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(v!=f)
   {
    dis[v][0]=e[i].w;
    dfs(v,u);
   }
  }
 }
 void calc(int n)
 {
  for(int i=1;i<=20;i++)
   for(int j=1;j<=n;j++)
    fa[j][i]=fa[fa[j][i-1]][i-1];
  for(int i=1;i<=20;i++)
   for(int j=1;j<=n;j++)
    dis[j][i]=max(dis[j][i-1],dis[fa[j][i-1]][i-1]);
 }
 int lca(int x,int y)
 {
  if(dep[x]>dep[y])swap(x,y);
  for(int i=20;i>=0;i--)
   if(dep[y]-(1<<i)>=dep[x])y=fa[y][i];
  if(x==y)return x;
  for(int i=20;i>=0;i--)
   if(fa[x][i]!=fa[y][i])
    x=fa[x][i],y=fa[y][i];
  return fa[x][0];
 }
 int findmax(int x,int y)
 {
  int ans=0;
  for(int i=20;i>=0;i--)
   if(dep[y]-(1<<i)>=dep[x])
   {
    ans=max(ans,dis[y][i]);
    y=fa[y][i];
   }
  return ans;
 }
 int find(int x,int y,int z)
 {
  return max(findmax(z,x),findmax(z,y));
 }
}g;
struct dsu
{
 int fa[100005];
 void init(int n)
 {
  for(int i=1;i<=n;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?x:fa[x]=find(fa[x]);
 }
 void unionn(int x,int y)
 {
  fa[find(y)]=find(x);
 }
}s;
int main()
{
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
 s.init(n);
 sort(ed+1,ed+m+1);
 int tot=0;
 for(int i=1;i<=m;i++)
  if(s.find(ed[i].u)!=s.find(ed[i].v))
  {
   s.unionn(ed[i].u,ed[i].v);
   tot++;
   g.addedge(ed[i].u,ed[i].v,ed[i].w);
   g.addedge(ed[i].v,ed[i].u,ed[i].w);
  }
 for(int i=1;i<=n;i++)
  if(!g.visit(i))g.dfs(i,i);
 g.calc(n);
 while(k--)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  if(s.find(x)!=s.find(y))puts("-1");
  else
  {
   int z=g.lca(x,y);
   printf("%d\n",g.find(x,y,z));
  }
 }
 return 0;
}