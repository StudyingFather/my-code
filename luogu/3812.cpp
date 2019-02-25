#include <iostream>
#include <algorithm>
using namespace std;
long long a[105],b[105],ans;
void work(long long x)
{
 for(int i=62;i>=0;i--)
 {
  if(!(x>>i))continue;
  if(!b[i])
  {
   b[i]=x;
   break;
  }
  x^=b[i];
 }
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  work(a[i]);
 }
 for(int i=62;i>=0;i--)
  ans=max(ans,ans^b[i]);
 cout<<ans<<endl;
 return 0;
}