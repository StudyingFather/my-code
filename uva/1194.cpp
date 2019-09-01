/*
 Name: UVa 1194
 Author: StudyingFather
 Date: 2019/08/14 11:42
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[10005];
int head[205],cur[205],dist[205],s,t,cnt;
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
 memcpy(cur,head,sizeof(cur));
 memset(dist,INF,sizeof(dist));
 dist[s]=0;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dist[e[i].v]>dist[u]+1)
   {
    dist[e[i].v]=dist[u]+1;
    q.push(e[i].v);
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
   int w=dfs(v,min(flow-used,e[i].w));
   if(w)
   {
    used+=w;
    e[i].w-=w;
    e[i^1].w+=w;
    if(used==flow)break;
   }
  }
 }
 return used;
}
int main()
{
 int n,m,k;
 while(~scanf("%d",&n))
 {
  if(!n)return 0;
  cnt=1;
  memset(head,0,sizeof(head));
  scanf("%d%d",&m,&k);
  s=n+m+1,t=n+m+2;
  for(int i=1;i<=k;i++)
  {
   int tmp,x,y;
   scanf("%d%d%d",&tmp,&x,&y);
   addedge(x,y+n,1);
   addedge(y+n,x,0);
  }
  for(int i=1;i<=n;i++)
  {
   addedge(s,i,1);
   addedge(i,s,0);
  }
  for(int i=1;i<=m;i++)
  {
   addedge(i+n,t,1);
   addedge(t,i+n,0);
  }
  int ans=0;
  while(bfs())
   ans+=dfs(s,INF);
  printf("%d\n",ans);
 }
}