#include <cstring>
#include <iostream>
#define MOD 999911658
using namespace std;
//999911658=2*3*4679*35617
const int p[]={0,2,3,4679,35617};
int n,g;
long long f[50005],invf[50005];
long long fpow(long long x,long long y,long long p)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%p;
  x=x*x%p;
  y>>=1;
 }
 return ans;
}
long long C(int x,int y,int p)
{
 if(x<y)return 0;
 return f[x]*invf[y]%p*invf[x-y]%p;
}
long long Lucas(int x,int y,int p)
{
 if(x==0)return 1;
 return C(x%p,y%p,p)*Lucas(x/p,y/p,p)%p;
}
long long calc(int p)
{
 f[0]=invf[0]=1;
 for(int i=1;i<p;i++)
  f[i]=f[i-1]*i%p;
 invf[p-1]=fpow(f[p-1],p-2,p);
 for(int i=p-2;i;i--)
  invf[i]=invf[i+1]*(i+1)%p;
 long long sum=0;
 for(int i=1;i*i<=n;i++)
  if(n%i==0)
  {
   sum=(sum+Lucas(n,i,p))%p;
   if(i*i!=n)sum+=(Lucas(n,n/i,p))%p;
  }
 return sum;
}
int main()
{
 cin>>n>>g;
 long long ans=0;
 if(g==MOD+1)
 {
  cout<<0<<endl;
  return 0;
 }
 for(int i=1;i<=4;i++)
 {
  long long x=calc(p[i]),y=MOD/p[i],invy=fpow(y,p[i]-2,p[i]);
  ans=(ans+x*y%MOD*invy)%MOD;
 }
 cout<<fpow(g,ans,MOD+1)<<endl;
 return 0;
}