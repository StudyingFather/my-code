#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 unsigned long long num,x;
}a[1005];
long long p[65];
bool cmp(const node&a,const node&b)
{
 return a.x>b.x;
}
bool add(unsigned long long x)
{
 for(int i=64;i>=0;i--)
  if((x>>i)&1)
  {
   if(!p[i])
   {
    p[i]=x;
    return true;
   }
   else x^=p[i];
  }
 return false;
}
int main()
{
 int n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i].num>>a[i].x;
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
  if(add(a[i].num))ans+=a[i].x;
 cout<<ans<<endl;
 return 0;
}