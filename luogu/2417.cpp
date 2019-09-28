/*
 Name: luogu P2417
 Author: StudyingFather
 Date: 2019/09/27 20:26
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
}e[5000005];
int head[100005],cur[100005],dist[100005],cnt,s,t;
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
 q.push(s),dist[s]=0;
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
   int w=dfs(v,min(flow,e[i].w));
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
 int T;
 scanf("%d",&T);
 while(T--)
 {
  int p,n;
  scanf("%d%d",&p,&n);
  s=p+n+1,t=p+n+2;
  memset(head,0,sizeof(head));
  cnt=1;
  for(int i=1;i<=p;i++)
  {
   int m;
   scanf("%d",&m);
   while(m--)
   {
    int x;
    scanf("%d",&x);
    addedge(i,x+p,1);
    addedge(x+p,i,0);
   }
   addedge(s,i,1);
   addedge(i,s,0);
  }
  for(int i=1;i<=n;i++)
   addedge(i+p,t,1),addedge(t,i+p,0);
  int ans=0;
  while(bfs())
   ans+=dfs(s,INF);
  puts(ans==p?"YES":"NO");
 }
 return 0;
}