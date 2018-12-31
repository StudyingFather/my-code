#include <iostream>
#define MOD 998244353
using namespace std;
int n;
int main()
{
 cin>>n;
 int a=-1,b=1;
 long long x=1,y=n-1,ans=0;
 for(int i=1;i<n;++i)
 {
  ans=(ans+i*x%MOD*y%MOD)%MOD;
  a++;b++;
  x=x*(long long)(n-a)%MOD;
  y=n-b;
 }
 cout<<(ans+1)%MOD;
 return 0;
}
