#include <stdio.h>
int main()
{
 int h1,m1,h2,m2;
 scanf("%d:%d",&h1,&m1);
 scanf("%d:%d",&h2,&m2);
 int t1=h1*60+m1,t2=h2*60+m2;
 int tm=(t1+t2)>>1;
 printf("%02d:%02d\n",tm/60,tm%60);
 return 0;
}