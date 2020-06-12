#include <iostream>
#include <algorithm>
using namespace std;
int cnt;
long long p[500005],n;
long long g(long long x,long long d)
{
 return x/d;
}
long long f(long long l,long long r,int d)
{
 return g(r,d)-g(l-1,d);
}
int main()
{
 cin>>n;
 for(long long i=1;i<=n;i*=2)
  for(long long j=i;j<=n;j*=5)
   p[++cnt]=j;
 sort(p+1,p+cnt+1);
 long long x=cnt,ans=0;
 for(long long l=1,r;l<=n;l=r+1)
 {
  r=n/(n/l);
  while(x&&p[x]>n/l)x--;
  long long sum=f(l,r,1)-f(l,r,2)-f(l,r,5)+f(l,r,10);
  ans+=sum*x*(n/l);
 }
 cout<<ans<<endl;
 return 0;
}