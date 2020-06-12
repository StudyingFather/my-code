#include <cstring>
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
long long f[100005];
int t[100005];
vector<int> e[100005];
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
long long dfs(int u)
{
 if(~f[u])
  return f[u];
 f[u]=0;
 for(auto v:e[u])
 {
  dfs(v);
  f[u]=(f[u]+f[v])%MOD;
 }
 f[u]=f[u]*fpow(t[u],MOD-2)%MOD;
 return f[u];
}
int main()
{
 ios::sync_with_stdio(false);
 memset(f,-1,sizeof(f));
 int n,m,x,y;
 long long ans=1;
 cin>>n>>m>>x>>y;
 f[x]=1;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  t[v]++;
 }
 for(int i=2;i<=n;i++)
 {
  ans=ans*(t[i]+(i==y))%MOD;
  f[x]=f[x]*t[i]%MOD;
 }
 f[x]=f[x]*fpow(t[x],MOD-2)%MOD;
 if(y==1)cout<<ans<<endl;
 else cout<<(ans-dfs(y)+MOD)%MOD<<endl;
 return 0;
}