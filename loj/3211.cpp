#include <cstring>
#include <cstdio>
#include <iostream>
#define MOD 998244353
using namespace std;
long long f[105][205],g[105][105],s[105],a[105][2005];
int main()
{
 freopen("meal.in","r",stdin);
 freopen("meal.out","w",stdout);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   cin>>a[i][j];
   s[i]=(s[i]+a[i][j])%MOD;
  }
 g[0][0]=1;
 for(int i=1;i<=n;i++)
  for(int j=0;j<=n;j++)
   g[i][j]=(g[i-1][j]+g[i-1][j-1]*s[i])%MOD;
 long long ans=0;
 for(int i=1;i<=n;i++)
  ans=(ans+g[n][i])%MOD;
 for(int p=1;p<=m;p++)
 {
  memset(f,0,sizeof(f));
  f[0][n+1]=1;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=2*n+1;j++)
    f[i][j]=(f[i-1][j]+f[i-1][j-1]*a[i][p]%MOD+f[i-1][j+1]*(s[i]-a[i][p]+MOD)%MOD)%MOD;
  for(int i=1;i<=n;i++)
   ans=(ans-f[n][n+1+i])%MOD;
 }
 cout<<(ans+MOD)%MOD<<endl;
 return 0;
}