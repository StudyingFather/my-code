// Problem: #505. 「LibreOJ β Round」ZQC 的游戏
// Contest: LibreOJ
// URL: https://loj.ac/problem/505
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[100005];
int head[505],cur[505],cnt,n,m,s,t;
int dis[505],vis[505];
struct player
{
 int x,y,w,r;
}p[105];
struct food
{
 int x,y,w;
}f[405];
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
 memset(dis,-1,sizeof(dis));
 memcpy(cur,head,sizeof(cur));
 dis[s]=0;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(e[i].w&&dis[v]==-1)
   {
    dis[v]=dis[u]+1;
    q.push(v);
   }
  }
 }
 return dis[t]!=-1;
}
int dfs(int u,int flow)
{
 if(u==t)return flow;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(dis[v]==dis[u]+1&&e[i].w)
  {
   int w=dfs(v,min(flow-used,e[i].w));
   e[i].w-=w;
   e[i^1].w+=w;
   used+=w;
   if(used==flow)break;
  }
 }
 return used;
}
bool check()
{
 for(int i=2;i<=n;i++)
  if(p[1].w<p[i].w)return false;
  else addedge(s,i,p[1].w-p[i].w),addedge(i,s,0);
 return true;
}
int calc(int x1,int y1,int x2,int y2)
{
 return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main()
{
 ios::sync_with_stdio(false);
 int T;
 cin>>T;
 while(T--)
 {
  memset(head,0,sizeof(head));
  memset(vis,0,sizeof(vis));
  cnt=1;
  int ans=0;
  cin>>n>>m;
  s=n+m+1,t=n+m+2;
  for(int i=1;i<=n;i++)
   cin>>p[i].x>>p[i].y>>p[i].w>>p[i].r,p[i].r*=p[i].r;
  for(int i=1;i<=m;i++)
   cin>>f[i].x>>f[i].y>>f[i].w;
  for(int j=1;j<=m;j++)
   if(calc(p[1].x,p[1].y,f[j].x,f[j].y)<=p[1].r)
    p[1].w+=f[j].w,f[j].w=0;
   else
    addedge(j+n,t,f[j].w),addedge(t,j+n,0);
  for(int i=2;i<=n;i++)
   for(int j=1;j<=m;j++)
    if(calc(p[i].x,p[i].y,f[j].x,f[j].y)<=p[i].r)
     addedge(i,j+n,INF),addedge(j+n,i,0),vis[j]=1;
  for(int j=1;j<=m;j++)
   if(vis[j])ans+=f[j].w;
  if(!check())
  {
   cout<<"qaq"<<endl;
   continue;
  }
  while(bfs())
   ans-=dfs(s,INF);
  if(!ans)cout<<"ZQC! ZQC!"<<endl;
  else cout<<"qaq"<<endl;
 }
 return 0;
}