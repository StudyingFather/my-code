#include <iostream>
#include <algorithm>
#define MOD 1000000009
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
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  cout<<fpow(n,n-1)<<endl;
 }
 return 0;
}