#include <iostream>
#define MOD 998244353
using namespace std;
int main()
{
 int n;
 long long ans=4;
 cin>>n;
 for(int i=2;i<=n;i++)
  ans=ans*3%MOD;
 cout<<ans<<endl;
 while(n--)
  cout<<"A 0 0 0 0"<<endl;
 return 0;
}