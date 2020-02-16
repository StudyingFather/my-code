#include <iostream>
#define MOD 1000000007
using namespace std;
long long f[1000005],invf[1000005],inv[1000005],g[1000005];
long long C(int x,int y)
{
 return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
long long P(int x,int y)
{
 return f[x]*invf[x-y]%MOD;
}
int main()
{
 int n,k,x;
 long long ans=0;
 cin>>n>>k>>x;
 inv[1]=1,f[0]=invf[0]=1;
 for(int i=2;i<=n;i++)
  inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
 for(int i=1;i<=n;i++)
 {
  f[i]=f[i-1]*i%MOD;
  invf[i]=invf[i-1]*inv[i]%MOD;
 }
 for(int i=0;i<=k;i++)
  g[i]=C(k,i)*P(n-i,k-i)%MOD;
 for(int i=x;i<=k;i++)
  if((i-x)%2==0)ans=(ans+C(i,x)*g[i])%MOD;
  else ans=((ans-C(i,x)*g[i])%MOD+MOD)%MOD;
 cout<<ans<<endl;
 return 0;
}