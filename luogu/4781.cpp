#include <iostream>
#define MOD 998244353
using namespace std;
struct point
{
 long long x,y;
}p[2005];
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
 long long n,k,ans=0;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>p[i].x>>p[i].y;
 for(int i=1;i<=n;i++)
 {
  long long tmp1=1,tmp2=1;
  for(int j=1;j<=n;j++)
   if(i!=j)
   {
    tmp1=tmp1*(k-p[j].x)%MOD;
    tmp2=tmp2*(p[i].x-p[j].x)%MOD;
    if(tmp1<0)tmp1+=MOD;
    if(tmp2<0)tmp2+=MOD;
   }
  ans=(ans+p[i].y*tmp1%MOD*fpow(tmp2,MOD-2)%MOD)%MOD;
  if(ans<0)ans+=MOD;
 }
 cout<<ans<<endl;
 return 0;
}