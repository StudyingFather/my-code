#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
vector<int> e[200005];
long long siz[200005],f[200005],n;
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
void dfs1(int u,int fa)
{
 siz[u]=1;
 for(auto v:e[u])
  if(v!=fa)
  {
   dfs1(v,u);
   siz[u]+=siz[v];
  }
 f[1]=f[1]*siz[u]%MOD;
}
void dfs2(int u,int fa)
{
 for(auto v:e[u])
  if(v!=fa)
  {
   f[v]=f[u]*(n-siz[v])%MOD*fpow(siz[v],MOD-2)%MOD;
   dfs2(v,u);
  }
}
int main()
{
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 f[1]=1;
 dfs1(1,0);
 dfs2(1,0);
 long long ans=1;
 for(int i=1;i<=n;i++)
  ans=ans*i%MOD;
 for(int i=1;i<=n;i++)
  cout<<ans*fpow(f[i],MOD-2)%MOD<<endl;
 return 0;
}