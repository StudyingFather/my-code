// Problem : #10192. 「一本通 5.6 练习 5」锯木厂选址
// Contest : LibreOJ
// URL : https://loj.ac/problem/10192
// Memory Limit : 32 MB
// Time Limit : 100 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
long long w[200005],d[200005],sd[200005],sw[200005],ans,sum;
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