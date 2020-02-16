#include <iostream>
#define MOD 998244353
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
 int n;
 cin>>n;
 cout<<26*fpow(25,n-1)%MOD<<endl;
 return 0;
}