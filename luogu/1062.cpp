#include <iostream>
using namespace std;
long long fpow(int x,int y)
{
 long long ans=1;
 for(int i=1;i<=y;i++)
  ans*=x;
 return ans;
}
int main()
{
 int k,n;
 long long ans=0;
 cin>>k>>n;
 for(int i=1,j=0;i<=n;i<<=1,j++)
  if(n&i)ans+=fpow(k,j);
 cout<<ans<<endl;
 return 0;
}