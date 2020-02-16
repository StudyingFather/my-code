#include <iostream>
using namespace std;
long long n;
long long phi(long long x)
{
 long long ans=x,x1=x;
 for(long long i=2;i*i<=x1;i++)
 {
  if(x%i==0)ans=ans*(i-1)/i;
  while(x%i==0)
   x/=i;
 }
 if(x!=1)ans=ans*(x-1)/x;
 return ans;
}
long long f(long long x)
{
 return x*phi(n/x);
}
int main()
{
 long long ans=0;
 cin>>n;
 for(long long i=1;i*i<=n;i++)
  if(n%i==0)
  {
   if(i*i!=n)ans+=f(i)+f(n/i);
   else ans+=f(i);
  }
 cout<<ans<<endl;
 return 0;
}