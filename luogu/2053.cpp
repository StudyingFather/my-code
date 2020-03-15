#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next;
}e[200005];
struct node
{
 int v,e;
}p[2005];
int head[2005],dis[2005],vis[2005];
int m,n,s,t,cnt=1,minc;
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
 memset(dis,INF,sizeof(dis));
 dis[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dis[u]+e[i].c<dis[e[i].v])
   {
    dis[e[i].v]=dis[u]+e[i].c;
    p[e[i].v].v=u;
    p[e[i].v].e=i;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 return dis[t]!=INF;
}
int f(int x,int y)
{
 return (x-1)*n+y;
}
int main()
{
 scanf("%d%d",&m,&n);
 s=n+m*n+1,t=n+m*n+2;
 for(int i=1;i<=n;i++)
  addedge(s,i,1,0),addedge(i,s,0,0);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   int x;
   scanf("%d",&x);
   for(int k=1;k<=n;k++)
   {
    addedge(i,n+f(j,k),1,x*k);
    addedge(n+f(j,k),i,0,-x*k);
   }
  }
 for(int j=1;j<=m;j++)
  for(int k=1;k<=n;k++)
  {
   addedge(n+f(j,k),t,1,0);
   addedge(t,n+f(j,k),0,0);
  }
 while(spfa())
 {
  int minw=INF;
  for(int i=t;i!=s;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=t;i!=s;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  minc+=minw*dis[t];
 }
 printf("%.2lf\n",minc*1.0/n);
 return 0;
}