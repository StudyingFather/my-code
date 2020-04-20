#include <iostream>
#include <algorithm>
using namespace std;
int dp[2005][2005],w[2005][15],f[2005][15];
int n,m;
void dfs(int u,int sta,int siz)
{
 for(int i=0;i<=siz;i++)
  dp[u][i]=0;
 if(siz==1)
 {
  for(int i=1;i<n;i++)
   if(sta&(1<<(i-1)))
    dp[u][1]+=w[u][i];
   else
    dp[u][0]+=f[u][i];
  return;
 }
 for(int k=0;k<2;k++)
 {
  dfs(u<<1,sta<<1|k,siz>>1);
  dfs(u<<1|1,sta<<1|k,siz>>1);
  for(int i=0;i<=min(siz,m);i++)
   for(int j=0;j<=min(siz,m);j++)
    dp[u][i+j]=max(dp[u][i+j],dp[u<<1][i]+dp[u<<1|1][j]);
 }
}
int main()
{
 cin>>n>>m;
 int p=1<<(n-1),q=(1<<n)-1,ans=0;
 for(int i=p;i<=q;i++)
  for(int j=1;j<n;j++)
   cin>>w[i][j];
 for(int i=p;i<=q;i++)
  for(int j=1;j<n;j++)
   cin>>f[i][j];
 dfs(1,0,q);
 for(int i=0;i<=m;i++)
  ans=max(ans,dp[1][i]);
 cout<<ans<<endl;
 return 0;
}