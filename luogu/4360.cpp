#include <iostream>
#include <algorithm>
using namespace std;
int w[20005],d[20005],sd[20005],sw[20005],ans,sum;
int q[20005];
double slope(int x,int y)
{
 return 1.0*(w[y]*d[y]-w[x]*d[x])/(w[y]-w[x]);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>w[i]>>d[i];
 for(int i=n;i;i--)
  d[i]+=d[i+1];
 for(int i=1;i<=n;i++)
 {
  sum+=d[i]*w[i];
  w[i]+=w[i-1];
 }
 ans=sum;
 int l=0,r=0;
 for(int i=1;i<=n;i++)
 {
  while(l<r&&slope(q[l],q[l+1])>d[i])
   l++;
  ans=min(ans,sum-w[q[l]]*d[q[l]]-(w[i]-w[q[l]])*d[i]);
  while(l<r&&slope(q[r-1],q[r])<slope(q[r],i))
   r--;
  q[++r]=i;
 }
 cout<<ans<<endl;
 return 0;
}