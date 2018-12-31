#include <iostream>
using namespace std;
int main()
{
 int n,k,ans=2e9;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
 {
  if(n%i)continue;
  int y=n/i;
  if(y>=k)continue;
  ans=min(i*k+y,ans);
 }
 cout<<ans<<endl;
 return 0;
}
