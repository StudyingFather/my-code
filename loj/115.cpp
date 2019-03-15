#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,lower,next;
}e[100005];
int n,m,s,t,sum,cnt=1;
int diff[205],head[205],dep[205],vis[205],cur[205];
void addedge(int u,int v,int w,int lower)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].lower=lower;
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
    if(used==w)break;
   }
  }
 }
 return used;
}
int main()
{
 scanf("%d%d",&n,&m);
 s=n+1,t=n+2;
 for(int i=1;i<=m;i++)
 {
  int s,t,lower,upper;
  scanf("%d%d%d%d",&s,&t,&lower,&upper);
  diff[s]-=lower;
  diff[t]+=lower;
  addedge(s,t,upper-lower,lower);
  addedge(t,s,0,lower);
 }
 for(int i=1;i<=n;i++)
  if(diff[i]>0)
  {
   sum+=diff[i];
   addedge(s,i,diff[i],0);
   addedge(i,s,0,0);
  }
  else
  {
   addedge(i,t,-diff[i],0);
   addedge(t,i,0,0);
  }
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 if(ans!=sum)puts("NO");
 else
 {
  puts("YES");
  for(int i=2;i<=2*m;i+=2)
   printf("%d\n",e[i].lower+e[i^1].w);
 }
 return 0;
}