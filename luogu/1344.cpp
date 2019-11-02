/*
 Name: luogu P1344
 Author: StudyingFather
 Date: 2019/10/17 00:35
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[2005];
int head[35],cur[35],dist[35],vis[35],cnt=1,n,m;
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
 dist[1]=0,vis[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(e[i].w&&dist[v]>dist[u]+1)
   {
    dist[v]=dist[u]+1;
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
  }
 }
 return dist[n]!=INF;
}
int dfs(int u,int flow)
{
 if(u==n)return flow;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  cur[u]=i;
  int v=e[i].v;
  if(e[i].w&&dist[v]==dist[u]+1)
  {
   int w=dfs(v,min(flow-used,e[i].w));
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
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w*1001+1);
  addedge(v,u,0);
 }
 long long ans=0;
 while(bfs())
  ans+=dfs(1,INF);
 cout<<ans/1001<<" "<<ans%1001<<endl;
 return 0;
}