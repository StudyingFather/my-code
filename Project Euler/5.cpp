#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
 return b==0?a:gcd(b,a%b);
}
long long ans=1;
int main()
{
 for(int i=1;i<=20;i++)
  ans=ans*i/gcd(ans,i);
 cout<<ans;
 return 0;
}
