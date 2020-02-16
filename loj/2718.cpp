#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
struct edge
{
 int v,w,next;
}e[800005];
struct node
{
 int u,v,l,a;
 bool operator<(const node&p)const
 {
  return a>p.a;
 }
}p[400005];
struct dsu
{
 int fa[400005];
 void init(int n)
 {
  for(int i=1;i<=n;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?x:fa[x]=find(fa[x]);
 }
 void set(int x,int y)
 {
  fa[x]=y;
 }
}d;
int head[200005],dis[200005],vis[200005];
int cnt,n,m;
int val[400005],fa[400005][25],mind[400005],dep[400005];
vector<int> tr[400005];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dijkstra()
{
 priority_queue<pii,vector<pii>,greater<pii> > q;
 memset(dis,63,sizeof(dis));
 memset(vis,0,sizeof(vis));
 dis[1]=0;
 q.push(make_pair(0,1));
 while(!q.empty())
 {
  int u=q.top().second;
  q.pop();
  if(vis[u])continue;
  vis[u]=1;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(dis[v]>dis[u]+e[i].w)
   {
    dis[v]=dis[u]+e[i].w;
    q.push(make_pair(dis[v],v));
   }
  }
 }
}
void build_retree()
{
 memset(val,0,sizeof(val));
 for(int i=1;i<=2*n;i++)
 {
  tr[i].clear();
  if(i<=n)mind[i]=dis[i];
  else mind[i]=1<<30;
 }
 cnt=n;
 sort(p+1,p+m+1);
 d.init(2*n);
 for(int i=1;i<=m;i++)
 {
  int u=p[i].u,v=p[i].v;
  int fu=d.find(u),fv=d.find(v);
  if(fu!=fv)
  {
   cnt++;
   val[cnt]=p[i].a;
   d.set(fu,cnt);
   d.set(fv,cnt);
   tr[cnt].push_back(fu);
   tr[cnt].push_back(fv);
  }
 }
}
void dfs(int u,int f)
{
 dep[u]=dep[f]+1;
 fa[u][0]=f;
 for(int i=1;i<=20;i++)
  fa[u][i]=fa[fa[u][i-1]][i-1];
 for(auto v:tr[u])
 {
  dfs(v,u);
  mind[u]=min(mind[u],mind[v]);
 }
}
int main()
{
 freopen("return.in","r",stdin);
 freopen("return.out","w",stdout);
 ios::sync_with_stdio(false);
 int T;
 cin>>T;
 while(T--)
 {
  cnt=0;
  memset(head,0,sizeof(head));
  memset(dep,0,sizeof(dep));
  memset(fa,0,sizeof(fa));
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
   cin>>p[i].u>>p[i].v>>p[i].l>>p[i].a;
   addedge(p[i].u,p[i].v,p[i].l);
   addedge(p[i].v,p[i].u,p[i].l);
  }
  dijkstra();
  build_retree();
  dfs(cnt,0);
  int Q,K,S,lastans=0;
  cin>>Q>>K>>S;
  while(Q--)
  {
   int v,p;
   cin>>v>>p;
   v=(v+K*lastans-1)%n+1;
   p=(p+K*lastans)%(S+1);
   for(int i=20;i>=0;i--)
    if(dep[v]>(1<<i)&&val[fa[v][i]]>p)v=fa[v][i];
   cout<<(lastans=mind[v])<<endl;
  }
 }
 return 0;
}