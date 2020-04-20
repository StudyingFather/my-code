#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
struct node
{
 int u,t,w;
 bool operator<(const node&a)const
 {
  return w>a.w;
 }
};
priority_queue<node> q;
int head[10005],dis[10005][25],vis[10005][25],cnt;
int a[10005];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int T;
 cin>>T;
 while(T--)
 {
  cnt=0;
  memset(head,0,sizeof(head));
  memset(dis,63,sizeof(dis));
  memset(vis,0,sizeof(vis));
  int n,m,k,s,t;
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
   cin>>a[i];
   if(a[i]==2)a[i]=-1;
  }
  for(int i=1;i<=m;i++)
  {
   int u,v,w;
   cin>>u>>v>>w;
   addedge(u,v,w);
   addedge(v,u,w);
  }
  cin>>s>>t;
  dis[s][k+a[s]]=0;
  q.push({s,k+a[s],0});
  while(!q.empty())
  {
   int u=q.top().u,t=q.top().t;
   q.pop();
   if(vis[u][t])continue;
   vis[u][t]=1;
   for(int i=head[u];i;i=e[i].next)
   {
    int v=e[i].v,nt=t+a[v];
    if(nt<=2*k&&nt>=0&&dis[v][nt]>dis[u][t]+e[i].w)
    {
     dis[v][nt]=dis[u][t]+e[i].w;
     q.push({v,nt,dis[v][nt]});
    }
   }
  }
  int ans=INF;
  for(int i=0;i<=2*k;i++)
   ans=min(ans,dis[t][i]);
  if(ans==INF)cout<<-1<<endl;
  else cout<<ans<<endl;
 }
 return 0;
}