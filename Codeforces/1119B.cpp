#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1005],b[1005],n,h;
bool check(int x)
{
 memcpy(b,a,sizeof(a));
 sort(b+1,b+x+1);
 int ch=0;
 for(int i=x;i>0;i-=2)
 {
  ch+=b[i];
  if(ch>h)break;
 }
 return ch<=h;
}
int main()
{
 cin>>n>>h;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 int l=1,r=n,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid))ans=mid,l=mid+1;
  else r=mid-1;
 }
 cout<<ans<<endl;
 return 0;
}