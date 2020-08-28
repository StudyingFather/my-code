// Problem: P4377 [USACO18OPEN]Talent Show G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4377
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#define eqs 1e-6
using namespace std;
struct cow
{
 int w,t;
}c[255];
int n,w;
double a[255],f[1005];
bool check(double x)
{
 for(int i=1;i<=n;i++)
  a[i]=c[i].t-x*c[i].w;
 for(int i=1;i<=w;i++)
  f[i]=-1e100;
 for(int i=1;i<=n;i++)
  for(int j=w;j>=0;j--)
   f[min(w,j+c[i].w)]=max(f[min(w,j+c[i].w)],f[j]+a[i]);
 return f[w]>=0;
}
int main()
{
 cin>>n>>w;
 for(int i=1;i<=n;i++)
  cin>>c[i].w>>c[i].t;
 double l=0,r=1000;
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))l=mid;
  else r=mid;
 }
 cout<<int(l*1000)<<endl;
 return 0;
}