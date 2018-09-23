#include <stdio.h>
int n[8],a,b,max,maxday;
int main()
{
 for(int i=1;i<=7;i++)
 {
  scanf("%d %d",&a,&b);
  n[i]=a+b;
  if(n[i]>8&&n[i]>max)
  {
   max=n[i];
   maxday=i;
  }
 }
 printf("%d",maxday);
 return 0;
}
