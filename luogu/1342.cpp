/*
 Name: luogu P1342
 Author: StudyingFather
 Date: 2019/09/16 18:54
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,q,next;
}e[2000005];
struct node
{
 int p;
 long long dist;
 bool operator<(const node&a)const
 {
  return dist>a.dist;
 }
};
int head[1000005],vis[1000005],cnt,n,m;
long long dist[1000005],ans;
priority_queue<node> que;
int read()
{
 int x=0;
 char ch=getchar();
 while(ch<'0'||ch>'9')
  ch=getchar();
 while(ch>='0'&&ch<='9')
  x=x*10+ch-'0',ch=getchar();
 return x;
}
inline void addedge(int u,int v,int w,int q)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].q=q;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void spfa(int q)
{
 memset(dist,INF,sizeof(dist));
 memset(vis,0,sizeof(vis));
 dist[1]=0;
 que.push({1,0});
 while(!que.empty())
 {
  int u=que.top().p;
  que.pop();
  if(vis[u])continue;
  vis[u]=1;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].q==q&&dist[e[i].v]>dist[u]+e[i].w)
   {
    dist[e[i].v]=dist[u]+e[i].w;
    que.push({e[i].v,dist[e[i].v]});
   }
 }
 for(int i=1;i<=n;i++)
  ans+=dist[i];
}
int main()
{
 n=read(),m=read();
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  u=read(),v=read(),w=read();
  addedge(u,v,w,0);
  addedge(v,u,w,1);
 }
 spfa(0),spfa(1);
 printf("%lld\n",ans);
 //printf("Time: %g\n",(double)clock()/CLOCKS_PER_SEC);
 return 0;
}