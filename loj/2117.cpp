#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;
struct dsu
{
 int fa[105];
 void init(int n)
 {
  for(int i=1;i<=n;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
 }
 bool merge(int x,int y)
 {
  int fx=find(x),fy=find(y);
  if(fx==fy)return false;
  fa[fy]=fx;
  return true;
 }
}d1,d2;
struct order
{
 int x,y;
 char s[5];
}p[105];
vector<int> e[105];
int t[105],siz[105];
long long f[105][105],c[105][105],g[105];
void dfs(int u)
{
 f[u][1]=1,siz[u]=1;
 for(auto v:e[u])
 {
  dfs(v);
  memset(g,0,sizeof(g));
  for(int i=1;i<=siz[u]+siz[v];i++)
   for(int j=1;j<=siz[u];j++)
    for(int k=1;k<=siz[v];k++)
    {
     int l=k-i+j;
     if(l<0)continue;
     g[i]=(g[i]+f[u][j]*f[v][k]%MOD*c[i-1][j-1]%MOD*c[j-1][l])%MOD;
    }
  for(int i=1;i<=siz[u]+siz[v];i++)
   f[u][i]=g[i];
  siz[u]+=siz[v];
 }
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=0;i<=n;i++)
  c[i][0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
 d1.init(n),d2.init(n);
 for(int i=1;i<=m;i++)
 {
  scanf("%d%s%d",&p[i].x,p[i].s,&p[i].y);
  if(p[i].s[0]=='=')d1.merge(p[i].x,p[i].y);
 }
 for(int i=1;i<=m;i++)
 {
  if(p[i].s[0]=='=')continue;
  int fx=d1.find(p[i].x),fy=d1.find(p[i].y);
  if(fx==fy)
  {
   puts("0");
   return 0;
  }
  if(d2.merge(fx,fy))
   e[fx].push_back(fy),t[fy]++;
  else
  {
   puts("0");
   return 0;
  }
 }
 for(int i=1;i<=n;i++)
  if(d1.find(i)==i&&t[i]==0)
   e[0].push_back(i);
 dfs(0);
 long long ans=0;
 for(int i=1;i<=n+1;i++)
  ans=(ans+f[0][i])%MOD;
 cout<<ans<<endl;
 return 0;
}