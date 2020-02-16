#include <cstring>
#include <iostream>
#define MOD 1000000007
using namespace std;
int a[10005];
int f[1000005],lf[1000005];
long long lcm=1;
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
void calc(int x)
{
 memset(f,0,sizeof(f));
 int x1=x;
 for(int i=2;x!=1&&i*i<=x1;i++)
 {
  while(x%i==0)
   x/=i,f[i]++;
  lf[i]=max(lf[i],f[i]);
 }
 if(x!=1)
 {
  f[x]++;
  lf[x]=max(lf[x],f[x]);
 }
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  calc(a[i]);
 }
 long long ans=0;
 for(int i=2;i<=1e6;i++)
  lcm=lcm*fpow(i,lf[i])%MOD;
 for(int i=1;i<=n;i++)
  ans=(ans+lcm*fpow(a[i],MOD-2))%MOD;
 cout<<ans<<endl;
 return 0;
}