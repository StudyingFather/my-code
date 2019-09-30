/*
 Name: luogu P5536
 Author: StudyingFather
 Date: 2019/09/30 15:58
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
int head[100005],dep[100005],maxd[100005],diff[100005],f[100005],cnt,d1,x;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa,int d)
{
 dep[u]=maxd[u]=d;
 f[u]=fa;
 if(dep[u]>d1)d1=dep[u],x=u;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=fa)
  {
   dfs(v,u,d+1);
   maxd[u]=max(maxd[v],maxd[u]);
  }
 }
}
bool cmp(int a,int b)
{
 return a>b;
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
 dfs(1,0,0);
 d1=0;
 dfs(x,0,0);
 for(int j=0;j<d1/2;j++)
  x=f[x];
 memset(maxd,0,sizeof(maxd));
 dfs(x,0,0);
 for(int i=1;i<=n;i++)
  diff[i]=maxd[i]-dep[i]+1;
 sort(diff+1,diff+n+1,cmp);
 int ans=0;
 for(int i=k+1;i<=n;i++)
  ans=max(ans,diff[i]);
 printf("%d\n",ans);
 return 0;
}