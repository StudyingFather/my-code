#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next;
}e[50005];
struct pre
{
 int v,e;
}p[5005];
int head[5005],dist[5005],vis[5005],cnt=1,s,t;
void addedge(int u,int v,int w,int c)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].c=c;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa()
{
 queue<int> q;
 memset(dist,-INF,sizeof(dist));
 memset(vis,0,sizeof(vis));
 dist[s]=0;
 vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dist[u]+e[i].c>dist[e[i].v])
   {
    dist[e[i].v]=dist[u]+e[i].c;
    p[e[i].v].e=i,p[e[i].v].v=u;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 return dist[t]!=-INF;
}
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 s=1,t=2*n*n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   int x;
   scanf("%d",&x);
   addedge(n*(i-1)+j,n*n+n*(i-1)+j,1,x);
   addedge(n*n+n*(i-1)+j,n*(i-1)+j,0,-x);
   addedge(n*(i-1)+j,n*n+n*(i-1)+j,k-1,0);
   addedge(n*n+n*(i-1)+j,n*(i-1)+j,0,0);
   if(j<n)
   {
    addedge(n*n+n*(i-1)+j,n*(i-1)+j+1,k,0);
    addedge(n*(i-1)+j+1,n*n+n*(i-1)+j,0,0);
   }
   if(i<n)
   {
    addedge(n*n+n*(i-1)+j,n*i+j,k,0);
    addedge(n*i+j,n*n+n*(i-1)+j,0,0);
   }
  }
 int maxc=0;
 while(spfa())
 {
  int minf=INF;
  for(int i=t;i!=s;i=p[i].v)
   minf=min(minf,e[p[i].e].w);
  if(!minf)break;
  for(int i=t;i!=s;i=p[i].v)
  {
   e[p[i].e].w-=minf;
   e[p[i].e^1].w+=minf;
  }
  maxc+=minf*dist[t];
 }
 printf("%d\n",maxc);
 return 0;
}