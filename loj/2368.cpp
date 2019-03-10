#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iterator>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
int head[405],cur[405],dep[405],vis[405];
int n,m,a,b,cnt=1,ans;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int bfs()
{
 queue<int> q;
 memset(dep,INF,sizeof(dep));
 memset(vis,0,sizeof(vis));
 memcpy(cur,head,sizeof(head));
 dep[a]=0;
 vis[a]=1;
 q.push(a);
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
 return dep[b]==INF?0:1;
}
int dfs(int p,int w)
{
 if(p==b)return w;
 int used=0;
 for(int i=cur[p];i;i=e[i].next)
 {
  cur[p]=i;
  if(dep[e[i].v]==dep[p]+1&&e[i].w)
  {
   int flow=dfs(e[i].v,min(w-used,e[i].w));
   if(flow)
   {
    used+=flow;
    e[i].w-=flow;
    e[i^1].w+=flow;
    if(used==w)return w;
   }
  }
 }
 return used;
}
void find_ans(int x)
{
 vis[x]=1;
 for(int i=head[x];i;i=e[i].next)
  if((!vis[e[i].v])&&e[i].w)find_ans(e[i].v);
}
int main()
{
 scanf("%d%d%d%d",&n,&m,&a,&b);
 b+=n;
 for(int i=1;i<=n;i++)
 {
  int c;
  scanf("%d",&c);
  addedge(i,i+n,c);
  addedge(i+n,i,0);
 }
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u+n,v,INF);
  addedge(v,u+n,0);
  addedge(v+n,u,INF);
  addedge(u,v+n,0);
 }
 while(bfs())
  ans+=dfs(a,INF);
 find_ans(a);
 set<int> res;
 for(int i=2;i<=cnt;i+=2)
  if(vis[e[i^1].v]&&(!vis[e[i].v]))res.insert(e[i^1].v);
 for(set<int>::iterator it=res.begin();it!=res.end();it++)
  printf("%d ",*it);
 return 0;
}