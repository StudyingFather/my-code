#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define INF 1e9
using namespace std;
struct edge
{
 int v,w;
 bool operator<(const edge&a)const
 {
  return v<a.v||(v==a.v&&w<a.w);
 }
};
set<edge> e[100005];
int dis[100005],vis[100005],ans,res,cnt,maxv,minv;
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
void dfs(int u,int d)
{
 if(dis[u])
 {
  ans=gcd(ans,abs(d-dis[u]));
  return;
 }
 dis[u]=d,vis[u]=1;
 maxv=max(maxv,dis[u]);
 minv=min(minv,dis[u]);
 for(auto i:e[u])
  dfs(i.v,d+i.w);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  e[u].insert({v,1});
  e[v].insert({u,-1});
 }
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   maxv=-INF,minv=INF;
   dfs(i,1);
   res+=maxv-minv+1;
  }
 if(ans)
 {
  if(ans<3)puts("-1 -1");
  else
   for(int i=3;i<=ans;i++)
    if(ans%i==0)
    {
     printf("%d %d\n",ans,i);
     break;
    }
 }
 else
 {
  if(res<3)puts("-1 -1");
  else printf("%d 3\n",res);
 }
 return 0;
}