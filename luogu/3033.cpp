#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[500005];
struct seg
{
 int x1,y1,x2,y2;
}se[255];
int head[255],cur[255],dis[255],vis[255],cnt=1,s,t;
int a[255],b[255],cnt1,cnt2;
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
 memcpy(cur,head,sizeof(cur));
 memset(dis,INF,sizeof(dis));
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
    q.push(v);
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
  if(dis[v]==dis[u]+1&&e[i].w)
  {
   int w=dfs(v,min(e[i].w,flow-used));
   used+=w;
   e[i].w-=w;
   e[i^1].w+=w;
   if(used==flow)break;
  }
 }
 return used;
}
int main()
{
 int n;
 scanf("%d",&n);
 s=n+1,t=n+2;
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d%d%d",&se[i].x1,&se[i].y1,&se[i].x2,&se[i].y2);
  if(se[i].x1==se[i].x2)
  {
   a[++cnt1]=i;
   addedge(s,i,1),addedge(i,s,0);
   if(se[i].y1>se[i].y2)swap(se[i].y1,se[i].y2);
  }
  else
  {
   b[++cnt2]=i;
   addedge(i,t,1),addedge(t,i,0);
   if(se[i].x1>se[i].x2)swap(se[i].x1,se[i].x2);
  }
 }
 for(int i=1;i<=cnt1;i++)
  for(int j=1;j<=cnt2;j++)
   if(se[a[i]].y1<=se[b[j]].y1&&se[b[j]].y1<=se[a[i]].y2&&
      se[b[j]].x1<=se[a[i]].x1&&se[a[i]].x1<=se[b[j]].x2)
   {
    addedge(a[i],b[j],1);
    addedge(b[j],a[i],0);
   }
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",n-ans);
 return 0;
}