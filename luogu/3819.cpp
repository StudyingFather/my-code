#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 long long x,r;
}a[100005];
bool cmp(const node&a,const node&b)
{
 return a.x<b.x;
}
int main()
{
 long long l,n,tot=0;
 cin>>l>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].x>>a[i].r;
  tot+=a[i].r;
 }
 sort(a+1,a+n+1,cmp);
 long long sum=0,ans=0,mid=0;
 for(int i=1;i<=n;i++)
 {
  sum+=a[i].r;
  if(sum>(tot+1)/2)
  {
   mid=i;
   break;
  }
 }
 for(int i=1;i<=n;i++)
  ans+=abs(a[i].x-a[mid].x)*a[i].r;
 cout<<ans<<endl;
 return 0;
}
