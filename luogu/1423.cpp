#include <stdio.h>
int cnt;
double ts,s=2;
int main()
{
 scanf("%lf",&ts);
 while(ts>0)
 {
  ts-=s;
  s*=0.98;
  cnt++;
 }
 printf("%d",cnt);
 return 0;
}
