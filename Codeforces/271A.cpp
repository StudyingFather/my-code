#include <stdio.h>
#include <string.h>
int y,a[15];
int check(int y)
{
 memset(a,0,sizeof(a));
 while(y)
 {
  int m=y%10;
  if(a[m])return 0;
  a[m]=1;
  y/=10;
 }
 return 1;
}
int main()
{
 scanf("%d",&y);
 y++;
 while(!check(y))
  y++;
 printf("%d",y);
 return 0;
}
