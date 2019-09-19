/*
 Name: luogu P2783
 Author: StudyingFather
 Date: 2019/09/19 20:18
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <stack>
using namespace std;
struct edge
{
 int v,next;
}e[100005],e2[100005];
int dfn[10005],low[10005],col[10005],vis[10005],cnte,cntc,cntp,n,m;
int head[10005],head2[10005],dep[10005],f[10005][25];
stack<int> s;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
void addedge2(int u,int v)
{
 e2[++cnte].v=v;
 e2[cnte].next=head2[u];
 head2[u]=cnte;
}
void dfs(int u,int fa)
{
 dfn[u]=low[u]=++cntp;
 vis[u]=1;
 s.push(u);
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  if(!dfn[v])
  {
   dfs(v,u);
   low[u]=min(low[u],low[v]);
  }
  else if(vis[v])low[u]=min(low[u],dfn[v]);
 }
 if(dfn[u]==low[u])
 {
  cntc++;
  while(1)
  {
   int p=s.top();
   s.pop();
   vis[p]=0;
   col[p]=cntc;
   if(p==u)break;
  }
 }
}
void dfs2(int u,int fa)
{
 for(int i=head2[u];i;i=e2[i].next)
 {
  int v=e2[i].v;
  if(v!=fa)
  {
   dep[v]=dep[u]+1;
   f[v][0]=u;
   dfs2(v,u);
  }
 }
}
int lca(int x,int y)
{
 if(dep[x]<dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[f[x][i]]>=dep[y])x=f[x][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
 return f[x][0];
}
int res[105];
void print(int x)
{
 int cnt=0;
 while(x)
 {
  res[++cnt]=x&1;
  x>>=1;
 }
 for(int i=cnt;i;i--)
  printf("%d",res[i]);
 puts("");
}
int main()
{
 int q;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=n;i++)
  if(!dfn[i])dfs(i,0);
 cnte=0;
 for(int i=1;i<=n;i++)
  for(int j=head[i];j;j=e[j].next)
   if(col[e[j].v]!=col[i])
    addedge2(col[i],col[e[j].v]);
 f[1][0]=1;
 dfs2(1,0);
 for(int i=1;i<=20;i++)
  for(int j=1;j<=cntc;j++)
   f[j][i]=f[f[j][i-1]][i-1];
 scanf("%d",&q);
 while(q--)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  print(dep[col[u]]+dep[col[v]]-2*dep[lca(col[u],col[v])]+1);
 }
 return 0;
}