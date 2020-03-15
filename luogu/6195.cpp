#include <iostream>
#define MOD 1000000007
using namespace std;
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
 long long n,m;
 cin>>n>>m;
 cout<<((n+1)*fpow(2,m)%MOD-1+MOD)%MOD<<endl;
 return 0;
}