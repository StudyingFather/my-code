/*
 Name: luogu P2899
 Author: StudyingFather
 Date: 2019/10/25 15:59
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[20005];
int f[10005][5],head[10005],n,cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 f[u][0]=1;
 int minn=10005;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  dfs(v,u);
  f[u][0]+=min(f[v][0],min(f[v][1],f[v][2]));
  f[u][1]+=min(f[v][0],f[v][1]);
  f[u][2]+=f[v][1];
  if(f[v][0]-f[v][1]<minn)minn=f[v][0]-f[v][1];
 }
 if(minn>0)f[u][1]+=minn;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 dfs(1,0);
 printf("%d\n",min(f[1][0],f[1][1]));
 return 0;
}