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
int n,m,s,t,cnt=1;
int head[100005],dep[100005],vis[100005],cur[100005];
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
 memset(dep,INF,sizeof(dep));
 memset(vis,0,sizeof(vis));
 memcpy(cur,head,sizeof(head));
 dep[s]=0;
 vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int p=q.front();
  q.pop();
  vis[p]=0;
  for(int i=head[p];i;i=e[i].next)
   if(dep[e[i].v]>dep[p]+1&&e[i].w)
   {
	dep[e[i].v]=dep[p]+1;
	if(!vis[e[i].v])
	{
	 vis[e[i].v]=1;
	 q.push(e[i].v);
	}
   }
 }
 if(dep[t]==INF)return 0;
 return 1;
}
int dfs(int p,int w)
{
 if(p==t)return w;
 int used=0;//已经使用的流量
 for(int i=cur[p];i;i=e[i].next)//每条边都尝试找一次增广路
 {
  cur[p]=i;//当前弧优化
  if(dep[e[i].v]==dep[p]+1&&e[i].w)
  {
   int flow=dfs(e[i].v,min(w-used,e[i].w));
   if(flow)
   {
	used+=flow;
	e[i].w-=flow;
	e[i^1].w+=flow;
	if(used==w)break;//残余流量用尽了就停止增广
   }
  }
 }
 return used;
}
int main()
{
 scanf("%d%d%d%d",&n,&m,&s,&t);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,0);
 }
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}