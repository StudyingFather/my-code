#include <iostream>
#include <algorithm>
#define MOD 100000007
#define INF 1e9
#define eqs 1e-7
using namespace std;
struct point
{
 int x,y;
}p[25];
int f[2500005][25],ans;
int g[25][25];
bool cmp(const point&a,const point&b)
{
 return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
double slope(int x1,int y1,int x2,int y2)
{
 if(x1==x2)return INF;
 return 1.0*(y1-y2)/(x1-x2);
}
int popcount(int x)
{
 int ans=0;
 while(x)
 {
  ans++;
  x&=(x-1);
 }
 return ans;
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>p[i].x>>p[i].y;
 sort(p+1,p+n+1,cmp);
 for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
   for(int k=i+1;k<=j-1;k++)
    if(abs(slope(p[i].x,p[i].y,p[k].x,p[k].y)-slope(p[k].x,p[k].y,p[j].x,p[j].y))<=eqs)
     g[i][j]|=(1<<k),g[j][i]|=(1<<k);
 for(int i=1;i<=n;i++)
  f[1<<i][i]=1;
 for(int i=0;i<(1<<(n+1));i++)
  for(int j=1;j<=n;j++)
   if(i&(1<<j))
    for(int k=1;k<=n;k++)
     if((i&(1<<k))==0&&k!=j&&(i&g[j][k])==g[j][k])
      f[i|(1<<k)][k]=(f[i|(1<<k)][k]+f[i][j])%MOD;
 for(int i=0;i<(1<<(n+1));i++)
  if(popcount(i)>=4)
   for(int j=1;j<=n;j++)
    if(i&(1<<j))ans=(ans+f[i][j])%MOD;
 cout<<ans<<endl;
 return 0;
}