#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,f,next;
}e[100005];
struct node
{
 int v,e;
}p[10005];
int head[5005],dist[5005],vis[5005];
int n,m,s,t,cnt=1,maxw,minf;
void addedge(int u,int v,int w,int f)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].f=f;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa()
{
 queue<int> q;
 memset(dist,INF,sizeof(dist));
 q.push(s);
 dist[s]=0;
 vis[s]=1;
 while(!q.empty())
 {
  int cur=q.front();
  q.pop();
  vis[cur]=0;
  for(int i=head[cur];i;i=e[i].next)
   if(e[i].w&&dist[cur]+e[i].f<dist[e[i].v])
   {
	dist[e[i].v]=dist[cur]+e[i].f;
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
int main()
{
 scanf("%d%d%d%d",&n,&m,&s,&t);
 for(int i=1;i<=m;i++)
 {
  int u,v,w,f;
  scanf("%d%d%d%d",&u,&v,&w,&f);
  addedge(u,v,w,f);
  addedge(v,u,0,-f);
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
  maxw+=minw;
  minf+=minw*dist[t];
 }
 printf("%d %d\n",maxw,minf);
 return 0;
}