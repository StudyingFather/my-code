#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[5005];
struct pre
{
 int v,e;
}p[5005];
int head[205],vis[205];
int n,m,c1,c2,cnt=1;
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
 vis[c1+n]=1;
 q.push(c1+n);
 while(!q.empty())
 {
  int cur=q.front();
  q.pop();
  for(int i=head[cur];i;i=e[i].next)
   if((!vis[e[i].v])&&e[i].w)
   {
   	p[e[i].v].v=cur;
   	p[e[i].v].e=i;
   	if(e[i].v==c2)return 1;
   	vis[e[i].v]=1;
   	q.push(e[i].v);
   }
 }
 return 0;
}
int main()
{
 scanf("%d%d%d%d",&n,&m,&c1,&c2);
 for(int i=1;i<=n;i++)
  addedge(i,i+n,1),addedge(i+n,i,0);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u+n,v,INF);
  addedge(v,u+n,0);
  addedge(v+n,u,INF);
  addedge(u,v+n,0);
 }
 int ans=0;
 while(bfs())
 {
  int minw=INF;
  for(int i=c2;i!=c1+n;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=c2;i!=c1+n;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  ans+=minw;
 }
 printf("%d\n",ans);
 return 0;
}
