#include <iostream>
#include <algorithm>
#define MOD 20100403
using namespace std;
long long f[2000005],invf[2000005];
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
long long c(long long x,long long y)
{
 return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
 int n,m;
 cin>>n>>m;
 f[0]=1;
 for(int i=1;i<=n+m;i++)
 {
  f[i]=(f[i-1]*i)%MOD;
  invf[i]=fpow(f[i],MOD-2);
 }
 cout<<(c(n+m,n)-c(n+m,m-1)+MOD)%MOD<<endl;
 return 0;
}