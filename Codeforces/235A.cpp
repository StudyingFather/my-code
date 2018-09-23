#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
 return b==0?a:gcd(b,a%b);
}
long long calc(long long x,long long y,long long z)
{
 long long d=gcd(x,y),g=x*y/d;
 d=gcd(g,z);
 return g*z/d;
}
int main()
{
 long long n;
 cin>>n;
 if(n==1)cout<<1;
 else if(n==2)cout<<2;
 else if(n==3)cout<<6;
 else if(n%2)cout<<n*(n-1)*(n-2);
 else
 {
  long long res=-1,a=1;
   for(long long i=max(a,n-50);i<n-1;i++)
    for(long long j=i+1;j<n;j++)
     for(long long k=j+1;k<=n;k++)
      res=max(res,calc(i,j,k));
  cout<<res;
 }
 return 0;
}
