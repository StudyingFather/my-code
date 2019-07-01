#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAXT 1000000
struct point
{
 double x,y;
}p[15];
int main()
{
 srand(19260817);
 //It's not recommend to use time(NULL) as the seed,for you can't always get AC.
 int n,l;
 scanf("%d%d",&n,&l);
 for(int i=1;i<=n;i++)
  scanf("%lf%lf",&p[i].x,&p[i].y);
 for(int i=1;i<=MAXT;i++)
 {
  double x=rand(),y=rand();//in Linux,RAND_MAX=INT_MAX
  while(x>l)
   x/=10;
  while(y>l)
   y/=10;
  bool flag=true;
  for(int j=1;j<=n;j++)
   if(pow(x-p[j].x,2)+pow(y-p[j].y,2)<pow(l*1.0/n,2))
   {
    flag=false;
    break;
   }
  if(flag)
  {
   printf("%.3lf %.3lf\n",x,y);
   return 0;
  }
 }
 puts("GG");
 return 0;
}
