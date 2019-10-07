/*
 Name: luogu P1343
 Author: StudyingFather
 Date: 2019/10/05 13:48
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[4005];
int head[205],cur[205],dist[205],s,t,cnt=1;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool bfs()
{
 queue<int> q;
 memset(dist,INF,sizeof(dist));
 memcpy(cur,head,sizeof(head));
 dist[s]=0,q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(e[i].w&&dist[v]>dist[u]+1)
   {
    dist[v]=dist[u]+1;
    q.push(v);
   }
  }
 }
 return dist[t]!=INF;
}
int dfs(int u,int flow)
{
 if(u==t)return flow;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  cur[u]=i;
  int v=e[i].v;
  if(e[i].w&&dist[v]==dist[u]+1)
  {
   int w=dfs(v,min(e[i].w,flow-used));
   used+=w;
   e[i].w-=w;
   e[i^1].w+=w;
   if(used==flow)break;
  }
 }
 return used;
}
int main()
{
 int n,m,x,ans=0;
 scanf("%d%d%d",&n,&m,&x);
 s=1,t=n;
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w),addedge(v,u,0);
 }
 while(bfs())
  ans+=dfs(s,INF);
 if(!ans)puts("Orz Ni Jinan Saint Cow!");
 else printf("%d %d\n",ans,int(ceil(x*1.0/ans)));
 return 0;
}