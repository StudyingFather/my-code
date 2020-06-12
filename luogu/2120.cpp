// Problem : P2120 [ZJOI2007]仓库建设
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P2120
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
long long d[1000005],p[1000005],c[1000005],f[1000005],sum;
int q[1000005];
double slope(int x,int y)
{
 return 1.0*(f[x]-f[y])/(p[y]-p[x]);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>d[i]>>p[i]>>c[i];
 for(int i=1;i<=n;i++)
  d[i]=d[n]-d[i];
 for(int i=1;i<=n;i++)
 {
  sum+=p[i]*d[i];
  p[i]+=p[i-1];
 }
 int l=0,r=0;
 for(int i=1;i<=n;i++)
 {
  while(l<r&&slope(q[l],q[l+1])>d[i])
   l++;
  f[i]=f[q[l]]+c[i]-(p[i]-p[q[l]])*d[i];
  while(l<r&&slope(q[r-1],q[r])<slope(q[r],i))
   r--;
  q[++r]=i;
 }
 cout<<sum+f[n]<<endl;
 return 0;
}