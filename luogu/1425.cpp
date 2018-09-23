#include <stdio.h>
int main()
{
 int h1,m1,h2,m2,h3,m3;
 scanf("%d%d%d%d",&h1,&m1,&h2,&m2);
 h3=h2-h1;
 m3=m2-m1;
 if(m3<0)
 {
  m3+=60;
  h3--;
 }
 printf("%d %d",h3,m3);
 return 0;
}
