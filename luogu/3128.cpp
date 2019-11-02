/*
 Name: luogu P3128
 Author: StudyingFather
 Date: 2019/11/01 18:27
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[100005];
int head[50005],dep[50005],fa[50005][25],res[50005],ans,cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs1(int u,int f)
{
 fa[u][0]=f;
 dep[u]=dep[f]+1;
 for(int i=head[u];i;i=e[i].next)
  if(dep[e[i].v]==-1)dfs1(e[i].v,u);
 return;
}
void dfs2(int u,int f)
{
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=f)
  {
   dfs2(e[i].v,u);
   res[u]+=res[e[i].v];
  }
 ans=max(ans,res[u]);
}
int lca(int x,int y)
{
 if(dep[x]>dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[y]-dep[x]-(1<<i)>=0)y=fa[y][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   x=fa[x][i];
   y=fa[y][i];
  }
 return fa[x][0];
}
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 memset(dep,-1,sizeof(dep));
 dfs1(1,0);
 for(int j=1;(1<<j)<=n;j++)
  for(int i=1;i<=n;i++)
   fa[i][j]=fa[fa[i][j-1]][j-1];
 for(int i=1;i<=k;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  int tmp=lca(x,y);
  res[x]++,res[y]++,res[tmp]--,res[fa[tmp][0]]--;
 }
 dfs2(1,0);
 printf("%d\n",ans);
 return 0;
}