#include <iostream>
#include <algorithm>
#define MOD 998244353
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
 long long t,n,m;
 cin>>t;
 while(t--)
 {
  cin>>n>>m;
  cout<<fpow(2,(n-1)*(m-1))<<endl;
 }
 return 0;
}