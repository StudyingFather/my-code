#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
 double x,y;
 bool operator<(const point&a)const
 {
  return x<a.x||(x==a.x&&y<a.y);
 }
 point operator-(const point&a)const
 {
  return {x-a.x,y-a.y};
 }
 double operator*(const point&a)const
 {
  return x*a.y-a.x*y;
 }
}p[10005],res[10005];
int sta[10005],vis[10005],t=0;
double ans;
double dist(point a,point b)
{
 return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%lf%lf",&p[i].x,&p[i].y);
 sort(p+1,p+n+1);
 sta[0]=1;
 t=1;
 for(int i=2;i<=n;i++)
 {
  while(t>=2&&(p[sta[t-1]]-p[sta[t-2]])*(p[i]-p[sta[t-1]])<=0)
  {
   vis[sta[t-1]]=0;
   t--;
  }
  vis[i]=1;
  sta[t++]=i;
 }
 int num=t;
 for(int i=n-1;i;i--)
  if(!vis[i])
  {
   while(t>num&&(p[sta[t-1]]-p[sta[t-2]])*(p[i]-p[sta[t-1]])<=0)
   {
    vis[sta[t-1]]=0;
    t--;
   }
   vis[i]=1;
   sta[t++]=i;
  }
 for(int i=0;i<t;i++)
  res[i]=p[sta[i]];
 for(int i=1;i<t;i++)
  ans+=dist(res[i-1],res[i]);
 printf("%.2lf\n",ans);
 return 0;
}