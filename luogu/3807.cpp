#include <iostream>
#include <algorithm>
using namespace std;
long long f[100005],n,m,p;
long long fpow(long long x,long long y)
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
long long C(long long x,long long y)
{
 if(x<y)return 0;
 return f[x]*fpow(f[y],p-2)%p*fpow(f[x-y],p-2)%p;
}
long long lucas(long long x,long long y)
{
 if(!y)return 1;
 return C(x%p,y%p)*lucas(x/p,y/p)%p;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  cin>>n>>m>>p;
  f[0]=1;
  for(int i=1;i<=p;i++)
   f[i]=f[i-1]*i%p;
  cout<<lucas(n+m,n)<<endl;
 }
 return 0;
}