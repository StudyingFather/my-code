/*
 Name: luogu P2996
 Author: StudyingFather
 Date: 2019/08/21 21:46
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[100005];
int head[50005],f[50005][2],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 f[u][1]=1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  dfs(v,u);
  f[u][0]+=max(f[v][0],f[v][1]);
  f[u][1]+=f[v][0];
 }
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
 printf("%d\n",max(f[1][0],f[1][1]));
 return 0;
}