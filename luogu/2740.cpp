#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 1000000000
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
struct node
{
 int v,e;
}p[10005];
int head[10005],vis[10005];
int n,m,cnt=1;
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
 memset(p,0,sizeof(p));
 memset(vis,0,sizeof(vis));
 vis[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int cur=q.front();
  q.pop();
  for(int i=head[cur];i;i=e[i].next)
   if((!vis[e[i].v])&&e[i].w)
   {
    p[e[i].v].v=cur;
    p[e[i].v].e=i;
    if(e[i].v==m)return 1;
    vis[e[i].v]=1;
    q.push(e[i].v);
   }
 }
 return 0;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,0);
 }
 int ans=0;
 while(bfs())
 {
  int minw=INF;
  for(int i=m;i!=1;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=m;i!=1;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  ans+=minw;
 }
 printf("%d\n",ans);
 return 0;
}
