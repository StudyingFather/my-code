#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long fpow(long long a,long long b)
{
 long long ans=1;
 while(b)
 {
  if(b&1)ans=ans*a%MOD;
  a=a*a%MOD;
  b>>=1;
 }
 return ans;
}
int main()
{
 long long n,p=1,q=0;
 cin>>n;
 long long inv100=fpow(100,MOD-2);
 for(int i=1;i<=n;i++)
 {
  long long a,b;
  cin>>a>>b;
  a=a*inv100%MOD;
  b=b*inv100%MOD;
  long long x=fpow((1-q*b%MOD+MOD)%MOD,MOD-2);
  p=p*a%MOD*x%MOD;
  q=(b+a*a%MOD*q%MOD*x%MOD)%MOD;
 }
 cout<<p<<endl;
 return 0;
}