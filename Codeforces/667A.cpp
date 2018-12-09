#include <stdio.h>
#define PI 3.1415926535897
int main()
{
 int d,h,v,e;
 scanf("%d%d%d%d",&d,&h,&v,&e);
 double s=(d*1.0/2)*(d*1.0/2)*PI,v1=s*e;
 if(v1>=v)puts("NO");
 else
 {
  puts("YES");
  printf("%.8lf",s*h/(v-v1));
 }
 return 0;
}
