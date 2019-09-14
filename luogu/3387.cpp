/*
 Name: luogu P3387
 Author: StudyingFather
 Date: 2019/09/10 14:51
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
struct edge
{
 int v,next;
}e1[100005],e2[100005];
int head1[10005],head2[10005],a[10005],b[10005],t[10005],f[10005];
int dfn[10005],low[10005],vis[10005],col[10005];
int cnte,cntp,cntc;
stack<int> s;
queue<int> q;
void addedge1(int u,int v)
{
 e1[++cnte].v=v;
 e1[cnte].next=head1[u];
 head1[u]=cnte;
}
void addedge2(int u,int v)
{
 e2[++cnte].v=v;
 e2[cnte].next=head2[u];
 head2[u]=cnte;
 t[v]++;
}
void dfs(int u)
{
 dfn[u]=low[u]=++cntp;
 vis[u]=1;
 s.push(u);
 for(int i=head1[u];i;i=e1[i].next)
 {
  int v=e1[i].v;
  if(!dfn[v])
  {
   dfs(v);
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
   b[cntc]+=a[p];
   col[p]=cntc;
   vis[p]=0;
   s.pop();
   if(p==u)break;
  }
 }
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge1(u,v);
 }
 cnte=0;
 for(int i=1;i<=n;i++)
  if(!dfn[i])dfs(i);
 for(int i=1;i<=n;i++)
  for(int j=head1[i];j;j=e1[j].next)
  {
   int v=e1[j].v;
   if(col[i]!=col[v])addedge2(col[i],col[v]);
  }
 for(int i=1;i<=cntc;i++)
  if(!t[i])q.push(i);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  f[u]+=b[u];
  for(int i=head2[u];i;i=e2[i].next)
  {
   int v=e2[i].v;
   t[v]--;
   f[v]=max(f[v],f[u]);
   if(!t[v])q.push(v);
  }
 }
 int ans=0;
 for(int i=1;i<=cntc;i++)
  ans=max(ans,f[i]);
 printf("%d\n",ans);
 return 0;
}