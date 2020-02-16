/*
 Name: luogu P4014
 Author: StudyingFather
 Date: 2019/10/13 20:41
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
 int v,w,c,next;
}e[40005];
struct node
{
 int v,e;
}p[205];
int head[205],dist[205],vis[205],cnt=1,s,t;
void addedge(int u,int v,int w,int c)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].c=c;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa(int op)
{
 queue<int> q;
 memset(dist,INF,sizeof(dist));
 dist[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int cur=q.front();
  q.pop();
  vis[cur]=0;
  for(int i=head[cur];i;i=e[i].next)
   if(e[i].w&&dist[cur]+(e[i].c)*op<dist[e[i].v])
   {
    dist[e[i].v]=dist[cur]+e[i].c*op;
    p[e[i].v].v=cur;
    p[e[i].v].e=i;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 return dist[t]!=INF;
}
int mfmc(int op)
{
 int ans=0;
 while(spfa(op))
 {
  int minw=INF;
  for(int i=t;i!=s;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=t;i!=s;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  ans+=minw*dist[t]*op;
 }
 return ans;
}
int main()
{
 int n;
 scanf("%d",&n);
 s=2*n+1,t=2*n+2;
 for(int i=1;i<=n;i++)
 {
  addedge(s,i,1,0);
  addedge(i,s,0,0);
  addedge(i+n,t,1,0);
  addedge(t,i+n,0,0);
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   int x;
   scanf("%d",&x);
   addedge(i,j+n,1,x);
   addedge(j+n,i,0,-x);
  }
 printf("%d\n",mfmc(1));
 for(int i=2;i<=cnt;i+=2)
  e[i].w+=e[i^1].w,e[i^1].w=0;
 printf("%d\n",mfmc(-1));
 return 0;
}