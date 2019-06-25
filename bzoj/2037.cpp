#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int x,y,v;
}a[1005];
int n,x0,f[2][1005][1005],m[1005];
bool cmp(const node&a,const node&b)
{
 return a.x<b.x;
}
int main()
{
 scanf("%d %d",&n,&x0);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i].x);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i].y);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i].v);
 sort(a+1,a+1+n,cmp);
 for(int i=1;i<=n;i++)
  m[i]=m[i-1]+a[i].v;
 for(int i=1;i<=n;i++)
  f[0][i][i]=f[1][i][i]=a[i].y-abs(a[i].x-x0)*m[n];
 for(int k=2;k<=n;k++)
  for(int i=1;i+k-1<=n;i++)
  {
   int j=k+i-1,l,r;
   l=(a[i].x-a[i+1].x)*(m[n]-m[j]+m[i])+f[0][i+1][j]+a[i].y;
   r=(a[i].x-a[j].x)*(m[n]-m[j]+m[i])+f[1][i+1][j]+a[i].y;
   f[0][i][j]=max(l,r);
   l=(a[j-1].x-a[j].x)*(m[n]-m[j-1]+m[i-1])+f[1][i][j-1]+a[j].y;
   r=(a[i].x-a[j].x)*(m[n]-m[j-1]+m[i-1])+f[0][i][j-1]+a[j].y;
   f[1][i][j]=max(l,r);
  }
 printf("%.3lf\n",max(f[0][1][n],f[1][1][n])/1000.0);
 return 0;
}
