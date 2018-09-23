#include <stdio.h>
int n,a,max=-2147483648,min=2147483647;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a);
  if(a>max)max=a;
  if(a<min)min=a;
 }
 printf("%d %d",min,max);
 return 0;
}
