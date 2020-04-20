#include <iostream>
#define MOD 1000000007
using namespace std;
long long f[1000005],inv[1000005],invf[1000005],g[1000005];
int t[1000005];
long long c(int x,int y)
{
 if(x<y)return 0;
 return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m,k;
 cin>>n>>m>>k;
 f[0]=invf[0]=1;
 for(int i=1;i<=n;i++)
 {
  if(i!=1)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
  else inv[1]=1;
  f[i]=f[i-1]*i%MOD;
  invf[i]=invf[i-1]*inv[i]%MOD;
 }
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  t[x]++;
 }
 for(int i=m;i;i--)
 {
  int cnt=0;
  for(int j=1;i*j<=m;j++)
  {
   cnt+=t[i*j];
   g[i]=(g[i]-g[i*j]+MOD)%MOD;
  }
  g[i]=((g[i]+c(cnt,k))%MOD+MOD)%MOD;
 }
 for(int i=1;i<=m;i++)
  cout<<g[i]<<' ';
 return 0;
}