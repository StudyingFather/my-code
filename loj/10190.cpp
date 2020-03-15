#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b,c;
long long x[1000005],f[1000005];
int q[1000005],l,r;
double slope(int p,int q)
{
 return ((f[p]-b*x[p]+a*x[p]*x[p])-(f[q]-b*x[q]+a*x[q]*x[q]))/(2.0*a*(x[p]-x[q]));
}
long long calc(long long x)
{
 return a*x*x+b*x+c;
}
int main()
{
 cin>>n>>a>>b>>c;
 for(int i=1;i<=n;i++)
 {
  cin>>x[i];
  x[i]+=x[i-1];
 }
 for(int i=1;i<=n;i++)
 {
  while(l<r&&slope(q[l],q[l+1])<=x[i])
   l++;
  int u=q[l];
  f[i]=f[u]+calc(x[i]-x[u]);
  while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i))
   r--;
  q[++r]=i;
 }
 cout<<f[n]<<endl;
 return 0;
}