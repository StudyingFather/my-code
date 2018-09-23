#include <stdio.h>
int a[10];
int main()
{
 int h,b=0;
 for(int i=1;i<=10;i++)
 {
  scanf("%d",&a[i]);
 }
 scanf("%d",&h);
 h+=30;
 for(int i=1;i<=10;i++)
 {
  if(a[i]<=h)b++;
 }
 printf("%d",b);
 return 0;
}
