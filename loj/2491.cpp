#include <iostream>
#define MOD 998244353
using namespace std;
struct edge
{
 int v,next;
}e[600005];
int dep[300005],head[300005],fa[300005][25],cnt;
long long dk[300005][55];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int f)
{
 dep[u]=dep[f]+1;
 fa[u][0]=f;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=f)dfs(e[i].v,u);
}
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int find(int x,int y)
{
 if(dep[x]>dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[y]-dep[x]-(1<<i)>=0)y=fa[y][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   x=fa[x][i];
   y=fa[y][i];
  }
 return fa[x][0];
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int x,y;
  cin>>x>>y;
  addedge(x,y),addedge(y,x);
 }
 dep[0]=-1;
 dfs(1,0);
 for(int j=1;(1<<j)<=n;j++)
  for(int i=1;i<=n;i++)
   fa[i][j]=fa[fa[i][j-1]][j-1];
 for(int j=1;j<=50;j++)
  for(int i=1;i<=n;i++)
   dk[i][j]=(dk[i-1][j]+fpow(i,j))%MOD;
 cin>>m;
 while(m--)
 {
  int x,y,z;
  cin>>x>>y>>z;
  int lca=find(x,y);
  int dx=dep[x],dy=dep[y],dlca=dep[lca];
  cout<<((dk[dx][z]+dk[dy][z]-2*dk[dlca][z]+fpow(dlca,z))%MOD+MOD)%MOD<<endl;
 }
 return 0;
}