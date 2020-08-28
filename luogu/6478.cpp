// Problem: P6478 [NOI Online #2 提高组]游戏（民间数据）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6478
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;
vector<int> e[5005];
char s[5005];
int siz[5005],siz1[5005],n;
long long f[5005][5005],g[5005],fr[5005];
int c[5005][5005];
void dfs(int u,int fa)
{
 siz[u]=1,siz1[u]=(s[u]-'0');
 f[u][0]=1;
 for(auto v:e[u])
 {
  if(v==fa)continue;
  dfs(v,u);
  for(int i=0;i<=siz[u]+siz[v];i++)
   g[i]=0;
  for(int i=0;i<=min(siz[u],n/2);i++)
   for(int j=0;j<=min(siz[v],n/2-i);j++)
    g[i+j]=(g[i+j]+f[u][i]*f[v][j])%MOD;
  for(int i=0;i<=siz[u]+siz[v];i++)
   f[u][i]=g[i];
  siz[u]+=siz[v],siz1[u]+=siz1[v];
 }
 for(int i=min(siz1[u],siz[u]-siz1[u]);i;i--)
  if(s[u]=='1')
   f[u][i]=(f[u][i]+f[u][i-1]*(siz[u]-siz1[u]-(i-1)))%MOD;
  else
   f[u][i]=(f[u][i]+f[u][i-1]*(siz1[u]-(i-1)))%MOD;
}
int main()
{
 cin>>n;
 cin>>(s+1);
 fr[0]=1;
 for(int i=1;i<=n;i++)
  fr[i]=fr[i-1]*i%MOD,c[i][0]=1;
 c[0][0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=i;j++)
   c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs(1,0);
 for(int i=0;i<=n/2;i++)
  f[1][i]=f[1][i]*fr[n/2-i]%MOD;
 for(int i=0;i<=n/2;i++)
 {
  long long ans=0;
  for(int j=i;j<=n/2;j++)
   if((j-i)&1)ans=(ans-c[j][i]*f[1][j]%MOD+MOD)%MOD;
   else ans=(ans+c[j][i]*f[1][j])%MOD;
  cout<<ans<<endl;
 }
 return 0;
}