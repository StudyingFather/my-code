#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],d[100005];
bool cmp(int x,int y)
{
 return x>y;
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m,k,ans;
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 ans=a[n]-a[1]+1;
 for(int i=2;i<=n;i++)
  d[i-1]=a[i]-a[i-1]-1;
 sort(d+1,d+n,cmp);
 for(int i=1;i<k;i++)
  ans-=d[i];
 cout<<ans<<endl;
 return 0;
}