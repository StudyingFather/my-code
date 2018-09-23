#include <stdio.h>
int h,m;
int is_huiwen()
{
 if(h/10==m%10&&h%10==m/10)return 1;
 return 0;
}
int main()
{
 scanf("%d:%d",&h,&m);
 if(is_huiwen())
 {
  printf("0");
  return 0;
 } 
 for(int i=1;;i++)
 {
  m++;
  if(m==60)
  {
   m=0;
   h++;
  }
  if(h==24)h=0;
  if(is_huiwen())
  {
   printf("%d",i);
   return 0;
  }
 }
}
