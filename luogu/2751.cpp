#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1005],g[1005],a[1005],b[1005],p[1005],q[1005];
int main()
{
 int n,m1,m2;
 cin>>n>>m1>>m2;
 for(int i=1;i<=m1;i++)
 {
  cin>>a[i];
  p[i]=a[i];
 }
 for(int i=1;i<=m2;i++)
 {
  cin>>b[i];
  q[i]=b[i];
 }
 memset(f,63,sizeof(f));
 memset(g,63,sizeof(g));
 for(int i=1;i<=n;i++)
 {
  int t1,t2;
  for(int j=1;j<=m1;j++)
   if(p[j]<f[i])t1=j,f[i]=p[j];
  for(int j=1;j<=m2;j++)
   if(q[j]<g[i])t2=j,g[i]=q[j];
  p[t1]+=a[t1],q[t2]+=b[t2];
 }
 int ans=0;
 for(int i=1;i<=n;i++)
  ans=max(ans,f[i]+g[n-i+1]);
 cout<<f[n]<<' '<<ans<<endl;
 return 0;
}