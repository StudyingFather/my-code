#include <iostream>
using namespace std;
long long m,a,c,x,n,g;
long long smul(long long x,long long y)
{
 long long ans=0;
 while(y)
 {
  if(y&1)ans=(ans+x)%m;
  x=(x+x)%m;
  y>>=1;
 }
 return ans;
}
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=smul(ans,x);
  x=smul(x,x);
  y>>=1;
 }
 return ans;
}
long long calc(long long n)
{
 if(n==1)return c;
 long long res=calc(n/2);
 res=(res+smul(res,fpow(a,n/2)))%m;
 if(n&1)res=(res+smul(fpow(a,n-1),c))%m;
 return res;
}
int main()
{
 cin>>m>>a>>c>>x>>n>>g;
 long long ans=smul(fpow(a,n),x);
 ans=(ans+calc(n))%m;
 cout<<ans%g<<endl;
 return 0;
}