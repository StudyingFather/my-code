#include <iostream>
#include <algorithm>
using namespace std;
long long a[55],b[55];
void add(long long x)
{
 for(int i=55;i;i--)
  if(x>>i)
  {
   if(!b[i])
   {
    b[i]=x;
    return;
   }
   x^=b[i];
  }
}
int main()
{
 long long n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  add(a[i]);
 }
 for(int i=55;i;i--)
  ans=max(ans,ans^b[i]);
 cout<<ans<<endl;
 return 0;
}