#include <cstdio>
#include <vector>
using namespace std;
const int sig=2;
struct graph
{
 struct edge
 {
  int v,w;
 };
 vector<edge> e[100005];
 void addedge(int u,int v,int w)
 {
  e[u].push_back({v,w});
 }
 vector<edge> getedge(int u)
 {
  return e[u];
 }
}g;
struct trie
{
 struct node
 {
  int son[sig];
 }tr[4000005];
 int cnt;
 void insert(int x)
 {
  int u=0;
  for(int i=30;i>=0;i--)
  {
   int num=(x>>i)&1;
   int&v=tr[u].son[num];
   if(!v)v=++cnt;
   u=v;
  }
 }
 int find(int x)
 {
  int u=0,ans=0;
  for(int i=30;i>=0;i--)
  {
   int num=(x>>i)&1;
   if(!tr[u].son[!num])u=tr[u].son[num];
   else u=tr[u].son[!num],ans+=(1<<i);
  }
  return ans;
 }
}t;
int dis[100005];
void dfs(int u,int fa)
{
 auto e=g.getedge(u);
 for(auto i:e)
 {
  int v=i.v;
  if(v!=fa)
  {
   dis[v]=dis[u]^i.w;
   dfs(v,u);
  }
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  g.addedge(u,v,w);
  g.addedge(v,u,w);
 }
 dfs(1,0);
 for(int i=1;i<=n;i++)
  t.insert(dis[i]);
 int ans=0;
 for(int i=1;i<=n;i++)
  ans=max(ans,t.find(dis[i]));
 printf("%d\n",ans);
 return 0;
}