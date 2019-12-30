#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define eqs 1e-8
using namespace std;
struct point
{
 double x,y;
}p[25];
int minx[1000005],f[1000005],l[25][25];
int main()
{
 int t;
 scanf("%d",&t);
 for(int i=0;i<(1<<18);i++)
  for(int j=1;;j++)
   if((i&(1<<(j-1)))==0)
   {
    minx[i]=j;
    break;
   }
 while(t--)
 {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
   scanf("%lf%lf",&p[i].x,&p[i].y);
  memset(f,INF,sizeof(f));
  memset(l,0,sizeof(l));
  f[0]=0;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
   {
    double x1=p[i].x,y1=p[i].y,x2=p[j].x,y2=p[j].y;
    if(abs(x2-x1)<=eqs)continue;
    double a=y2/(x2*(x2-x1))-y1/(x1*(x2-x1));
    double b=y2*x1/(x2*(x1-x2))-y1*x2/(x1*(x1-x2));
    if(a>=0)continue;
    for(int k=1;k<=n;k++)
    {
     double x=p[k].x,y=p[k].y;
     if(abs(a*x*x+b*x-y)<=eqs)l[i][j]|=1<<(k-1);
    }
   }
  for(int i=0;i<(1<<n);i++)
  {
   f[i|(1<<(minx[i]-1))]=min(f[i|(1<<(minx[i]-1))],f[i]+1);
   for(int j=1;j<=n;j++)
    f[i|l[minx[i]][j]]=min(f[i|l[minx[i]][j]],f[i]+1);
  }
  printf("%d\n",f[(1<<n)-1]);
 }
 return 0;
}