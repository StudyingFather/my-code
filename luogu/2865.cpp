#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
int head[5005],d1[5005],d2[5005],vis[5005],cnt;
queue<int> q;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n,r;
 scanf("%d%d",&n,&r);
 for(int i=1;i<=r;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,w);
 }
 memset(d1,INF,sizeof(d1));
 memset(d2,INF,sizeof(d2));
 d1[1]=0,vis[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(d1[v]>d1[u]+e[i].w)
   {
    d2[v]=d1[v];
    d1[v]=d1[u]+e[i].w;
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
   if(d2[v]>d1[u]+e[i].w&&d1[v]<d1[u]+e[i].w)
   {
    d2[v]=d1[u]+e[i].w;
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
   if(d2[v]>d2[u]+e[i].w)
   {
    d2[v]=d2[u]+e[i].w;
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
  }
 }
 printf("%d\n",d2[n]);
 return 0;
}