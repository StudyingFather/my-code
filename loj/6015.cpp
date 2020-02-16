#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[1000005];
struct ship
{
 int h,r;
 vector<int> s;
}a[25];
struct dsu
{
 int fa[25];
 void init(int x)
 {
  for(int i=1;i<=x;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?x:fa[x]=find(fa[x]);
 }
 void unionn(int x,int y)
 {
  fa[y]=x;
 }
}d;
int s=100000,t=100001,cnt=1;
int head[100005],dep[100005],vis[100005],cur[100005];
int id[25],lid[25];
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
 int n,m,k;
 cin>>n>>m>>k;
 d.init(n+2);
 for(int i=1;i<=m;i++)
 {
  cin>>a[i].h>>a[i].r;
  int last=0;
  for(int j=1;j<=a[i].r;j++)
  {
   int x;
   cin>>x;
   if(x==0)x=n+1;
   if(x==-1)x=n+2;
   if(j==1)last=x;
   else d.unionn(d.find(last),d.find(x)),last=x;
   a[i].s.push_back(x);
  }
 }
 if(d.find(n+1)!=d.find(n+2))cout<<0<<endl;
 else
 {
  int ans=0,tot=0;
  for(int i=1;i<=n+2;i++)
  {
   lid[i]=++tot;
   if(i==n+1)
    addedge(s,tot,INF),addedge(tot,s,0);
   if(i==n+2)
    addedge(tot,t,INF),addedge(t,tot,0);
  }
  do
  {
   ans++;
   for(int i=1;i<=n+2;i++)
   {
    id[i]=++tot;
    addedge(lid[i],id[i],INF),addedge(id[i],lid[i],0);
    if(i==n+1)
     addedge(s,tot,INF),addedge(tot,s,0);
    if(i==n+2)
     addedge(tot,t,INF),addedge(t,tot,0);
   }
   for(int i=1;i<=m;i++)
   {
    int t=ans%a[i].r;
    int u=(t==0?a[i].s[a[i].r-1]:a[i].s[t-1]),v=a[i].s[t];
    addedge(lid[u],id[v],a[i].h),addedge(id[v],lid[u],0);
   }
   while(bfs())
    k-=dfs(s,INF);
   memcpy(lid,id,sizeof(id));
  }while(k>0);
  cout<<ans<<endl;
 }
 return 0;
}