#include <stdio.h>
int n,max,maxn,a,b;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a,&b);
  if(a*b>=maxn)
  {
   maxn=a*b;
   max=i;
  }
  printf("%d\n",a*b);
 }
 printf("%d",max);
 return 0;
}
