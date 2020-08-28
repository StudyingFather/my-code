// Problem: P3336 [ZJOI2013]话旧
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3336
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#define MOD 19940417
using namespace std;
struct point
{
 int x,y;
 bool operator==(const point&a)const
 {
  return x==a.x;
 }
 bool operator<(const point&a)const
 {
  return x<a.x;
 }
}p[1000005];
int n,k;
int f[1000005][2];
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>k;
 for(int i=1;i<=k;i++)
  cin>>p[i].x>>p[i].y;
 p[++k].x=0,p[++k].x=n;
 sort(p+1,p+k+1);
 k=unique(p+1,p+k+1)-p-1;
 f[1][1]=1;
 int maxy=0;
 for(int i=1;i<k;i++)
 {
  int x1=p[i].x,y1=p[i].y,x2=p[i+1].x,y2=p[i+1].y;
  int x01=x1+y1,x02=x2-y2;
  int d=(x02-x01)/2;
  if(f[i][0]||y1==0)maxy=max(maxy,(x2+y2-x1+y1)/2);
  if(x2-x1==y2-y1)//up only
   f[i+1][0]=((y1==0)*f[i][1]+f[i][0])%MOD;
  else if(x2-x1==y1-y2)//down only
   f[i+1][1]=(f[i][0]+f[i][1])%MOD;
  else if(d<0)//up first,then down only
   f[i+1][1]=f[i][0];
  else if(d==0)
  {
   f[i+1][0]=(f[i][0]+f[i][1])%MOD;//down then up immediately
   f[i+1][1]=f[i][0];//only up then down
  }
  else
  {
   long long tmp=fpow(2,d-1);
   if(y2)f[i+1][0]=(2*f[i][0]*tmp+f[i][1]*tmp)%MOD;
   f[i+1][1]=(2*f[i][0]*tmp+f[i][1]*tmp)%MOD;
  }
 }
 cout<<f[k][1]<<' '<<maxy<<endl;
 return 0;
}