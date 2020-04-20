#include <cmath>
#include <iostream>
#define INF 1e9
using namespace std;
long long d[500005];
int main()
{
 ios::sync_with_stdio(false);
 int n,q;
 cin>>n>>q;
 d[0]=1;
 for(int i=1;i<=n;i++)
 {
  cin>>d[i];
  d[i]=(d[i-1]>=INF?INF:d[i-1]*ceil(1.0*d[i]/d[i-1]));
 }
 while(q--)
 {
  int t,L,R;
  cin>>t>>L>>R;
  int ans1=-1,ans2=-2;
  int l=0,r=n;
  while(l<=r)
  {
   int mid=(l+r)>>1;
   int res=t/d[mid]*d[mid]-mid;
   if(res>=L&&res<=R)ans1=mid,r=mid-1;
   else if(res<L)r=mid-1;
   else l=mid+1;
  }
  l=0,r=n;
  while(l<=r)
  {
   int mid=(l+r)>>1;
   int res=t/d[mid]*d[mid]-mid;
   if(res>=L&&res<=R)ans2=mid,l=mid+1;
   else if(res<L)r=mid-1;
   else l=mid+1;
  }
  cout<<ans2-ans1+1<<endl;
 }
 return 0;
}