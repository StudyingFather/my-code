#include <iostream>
#define MOD 9999991
using namespace std;
int main()
{
 long long n,ans=1;
 cin>>n;
 for(int i=1;i<=n-2;i++)
  ans=(ans*n)%MOD;
 for(int i=1;i<=n-1;i++)
  ans=(ans*i)%MOD;
 cout<<ans<<endl;
 return 0;
}
