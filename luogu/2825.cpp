#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[50005];
int head[5005],cur[5005],cnt=1;
int dis[5005],vis[5005],s,t,n,m,ans;
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
 memset(dis,INF,sizeof(dis));
 memcpy(cur,head,sizeof(cur));
 dis[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(e[i].w&&dis[v]>dis[u]+1)
   {
    dis[v]=dis[u]+1;
    if(!vis[v])q.push(v),vis[v]=1;
   }
  }
 }
 return dis[t]!=INF;
}
int dfs(int u,int flow)
{
 if(u==t)return flow;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  int v=e[i].v;
  cur[u]=i;
  if(e[i].w&&dis[v]==dis[u]+1)
  {
   int f=dfs(v,min(flow-used,e[i].w));
   e[i].w-=f;
   e[i^1].w+=f;
   used+=f;
   if(used==flow)break;
  }
 }
 return used;
}
int px[55][55],py[55][55];
char str[55][55];
int main()
{
 scanf("%d%d",&n,&m);
 s=2*n*m+1,t=2*n*m+2;
 for(int i=1;i<=n;i++)
  scanf("%s",str[i]+1);
 int tot=0;
 for(int x=1;x<=n;x++)
 {
  bool flag=true;
  for(int y=1;y<=m;y++)
  {
   if(flag&&str[x][y]!='#')
   {
    tot++,flag=false;
    addedge(s,tot,1),addedge(tot,s,0);
   }
   if(str[x][y]!='#')
    px[x][y]=tot;
   else flag=true;
  }
 }
 for(int y=1;y<=m;y++)
 {
  bool flag=true;
  for(int x=1;x<=n;x++)
  {
   if(flag&&str[x][y]!='#')
   {
    tot++,flag=false;
    addedge(tot,t,1),addedge(t,tot,0);
   }
   if(str[x][y]!='#')
    py[x][y]=tot;
   else flag=true;
  }
 }
 for(int x=1;x<=n;x++)
  for(int y=1;y<=m;y++)
   if(str[x][y]=='*')
   {
    addedge(px[x][y],py[x][y],1);
    addedge(py[x][y],px[x][y],0);
   }
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}