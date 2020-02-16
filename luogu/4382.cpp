#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,rev;
 };
 vector<edge> e[505];
 int cnt=1,s,t;
 int vis[505],cur[505],dis[505];
 void addedge(int u,int v,int w)
 {
  e[u].push_back({v,w,(int)e[v].size()});
  e[v].push_back({u,0,(int)e[u].size()-1});
 }
 void deledge(int u,int v)
 {
  e[u].pop_back();
  e[v].pop_back();
 }
 void init(int S,int T)
 {
  cnt=1;
  for(int i=1;i<=T;i++)
   e[i].clear();
  s=S,t=T;
 }
 bool bfs()
 {
  queue<int> q;
  memset(dis,INF,sizeof(dis));
  memset(cur,0,sizeof(cur));
  dis[s]=0,vis[s]=1;
  q.push(s);
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(auto ed:e[u])
    if(ed.w&&dis[ed.v]>dis[u]+1)
    {
     dis[ed.v]=dis[u]+1;
     if(!vis[ed.v])q.push(ed.v);
    }
  }
  return dis[t]!=INF;
 }
 int dfs(int u,int flow)
 {
  if(u==t)return flow;
  int siz=e[u].size(),used=0;
  for(int i=cur[u];i<siz;i++)
  {
   cur[u]=i;
   int v=e[u][i].v;
   if(dis[v]==dis[u]+1&&e[u][i].w)
   {
    int w=dfs(v,min(e[u][i].w,flow-used)),rev=e[u][i].rev;
    e[u][i].w-=w;
    e[v][rev].w+=w;
    used+=w;
    if(used==flow)break;
   }
  }
  return used;
 }
}g[205];
int n,m,s,t,b[205],p[205];
vector<int> a[205][205];
namespace pro1
{
 int res[205];
 void init()
 {
  for(int i=1;i<=n;i++)
   res[i]=m+1;
  for(int i=1;i<=m;i++)
   g[0].addedge(i+n,t,b[i]);
 }
 void solve()
 {
  init();
  int ans=0;
  for(int i=1;i<=n;i++)
  {
   g[i]=g[i-1];
   g[i].addedge(s,i,1);
   for(int j=1;j<=m;j++)
   {
    bool flag=false;
    for(auto v:a[i][j])
     g[i].addedge(i,v+n,1);
    while(g[i].bfs())
     ans+=g[i].dfs(s,INF),flag=true;
    if(!flag)
     for(auto v:a[i][j])
      g[i].deledge(i,v+n);
    else
    {
     res[i]=j;
     break;
    }
   }
  }
  for(int i=1;i<=n;i++)
   cout<<res[i]<<' ';
  cout<<endl;
 }
}
namespace pro2
{
 int res[205],vis[205];
 bool check(int x,int u)
 {
  auto G=g[x-1];
  G.addedge(s,u,1);
  for(int i=1;i<=p[u];i++)
   for(auto v:a[u][i])
    G.addedge(u,v+n,1);
  return G.bfs();
 }
 void solve()
 {
  memset(res,0,sizeof(res));
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
   if(pro1::res[i]<=p[i])
   {
    res[i]=0;
    continue;
   }
   int l=1,r=i-1;
   while(l<=r)
   {
    int mid=(l+r)>>1;
    if(check(mid,i))vis[i]=mid,l=mid+1;
    else r=mid-1;
   }
   res[i]=(vis[i]?i-vis[i]:i);
  }
  for(int i=1;i<=n;i++)
   cout<<res[i]<<' ';
  cout<<endl;
 }
}
int main()
{
 ios::sync_with_stdio(false);
 int T,c;
 cin>>T>>c;
 while(T--)
 {
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    a[i][j].clear();
  cin>>n>>m;
  s=n+m+1,t=n+m+2;
  g[0].init(n+m+1,n+m+2);
  for(int i=1;i<=m;i++)
   cin>>b[i];
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   {
    int x;
    cin>>x;
    if(x)a[i][x].push_back(j);
   }
  for(int i=1;i<=n;i++)
   cin>>p[i];
  pro1::solve();
  pro2::solve();
 }
 return 0;
}