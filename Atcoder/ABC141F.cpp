#include <iostream>
using namespace std;
long long p[65],a[100005];
void insert(long long x)
{
 for(int i=60;i>=0;i--)
 {
  if(!(x>>i))continue;
  if(!p[i])
  {
   p[i]=x;
   break;
  }
  x^=p[i];
 }
}
long long query()
{
 long long ans=0;
 for(int i=60;i>=0;i--)
  ans=max(ans,ans^p[i]);
 return ans;
}
int main()
{
 int n;
 cin>>n;
 long long sum=0,ans=0;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  sum^=a[i];
 }
 for(int i=1;i<=n;i++)
 {
  a[i]&=(~sum);
  insert(a[i]);
 }
 ans=query();
 cout<<ans*2+sum<<endl;
 return 0;
}
