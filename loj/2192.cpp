#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
double p[500005],f[500005];
vector<pair<int,double> > e[500005];
void dfs1(int u,int fa)
{
 f[u]=(1-p[u]);
 for(auto E:e[u])
 {
  int v=E.first;
  double w=E.second;
  if(v==fa)continue;
  dfs1(v,u);
  f[u]*=(f[v]+(1-w)-f[v]*(1-w));
 }
}
void dfs2(int u,int fa)
{
 for(auto E:e[u])
 {
  int v=E.first;
  double w=E.second;
  if(v==fa)continue;
  double tmp=f[u]/(f[v]+(1-w)-f[v]*(1-w));
  f[v]*=(tmp+(1-w)-tmp*(1-w));
  dfs2(v,u);
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v,p;
  scanf("%d%d%d",&u,&v,&p);
  e[u].push_back({v,p/100.0});
  e[v].push_back({u,p/100.0});
 }
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  p[i]=x/100.0;
 }
 dfs1(1,1);
 dfs2(1,1);
 double ans=0;
 for(int i=1;i<=n;i++)
  ans+=(1-f[i]);
 printf("%.6lf\n",ans);
 return 0;
}