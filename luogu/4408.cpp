/*
 Name: luogu P4408
 Author: StudyingFather
 Date: 2019/09/18 23:02
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
long long dist[100005],maxd,ans;
int head[100005],cnt,s;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=fa)
  {
   dist[v]=min(dist[v],dist[u]+e[i].w);
   if(dist[v]>maxd)s=v,maxd=dist[v];
   dfs(v,u);
  }
 }
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 memset(dist,INF,sizeof(dist));
 dist[1]=0;
 dfs(1,0);
 maxd=0,memset(dist,INF,sizeof(dist)),dist[s]=0;
 dfs(s,0);
 ans=maxd,maxd=0,dist[s]=0;
 dfs(s,0);
 cout<<ans+maxd<<endl;
 return 0;
}