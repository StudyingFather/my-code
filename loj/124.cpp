#include <iostream>
#define MOD 1000000007
using namespace std;
long long s[10000005],pri[10000005],cnt;
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
int main()
{
 int n,k;
 long long ans=0;
 cin>>n>>k;
 s[1]=1;
 for(int i=2;i<=n;i++)
 {
  if(!s[i])
   s[i]=fpow(i,k),pri[++cnt]=i;
  for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
  {
   s[i*pri[j]]=s[i]*s[pri[j]]%MOD;
   if(i%pri[j]==0)break;
  }
 }
 for(int i=1;i<=n;i++)
  ans=(ans+n/i*s[i])%MOD;
 cout<<ans<<endl;
 return 0;
}