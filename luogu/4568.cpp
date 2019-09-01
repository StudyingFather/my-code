/*
 Name: luogu P4568
 Author: StudyingFather
 Date: 2019/08/13 21:36
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
}e[100005];
struct node
{
 int p,used,dist;
 bool operator<(const node&a)const
 {
  return dist>a.dist;
 }
};
priority_queue<node> q;
int head[10005],dist[10005][25],vis[10005][25],n,m,s,t,k,cnt;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void spfa()
{
 memset(dist,INF,sizeof(dist));
 dist[s][0]=0;
 q.push({s,0,0});
 while(!q.empty())
 {
  int u=q.top().p,used=q.top().used;
  q.pop();
  vis[u][used]=false;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(used<=k&&dist[v][used+1]>dist[u][used])
   {
    dist[v][used+1]=dist[u][used];
    if(!vis[v][used+1])
    {
     q.push({v,used+1,dist[v][used+1]});
     vis[v][used+1]=true;
    }
   }
   if(dist[v][used]>dist[u][used]+e[i].w)
   {
    dist[v][used]=dist[u][used]+e[i].w;
    if(!vis[v][used])
    {
     q.push({v,used,dist[v][used]});
     vis[v][used]=true;
    }
   }
  }
 }
}
int main()
{
 scanf("%d%d%d",&n,&m,&k);
 scanf("%d%d",&s,&t);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,w);
 }
 spfa();
 int ans=INF;
 for(int i=0;i<=k;i++)
  ans=min(ans,dist[t][i]);
 printf("%d\n",ans);
 return 0;
}