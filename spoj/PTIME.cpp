#include <stdio.h>
int a[10005],n,first=1;
int main()
{
 scanf("%d",&n);
 for(int i=2;i<=n;i++)
 {
  int p=i;
  for(int j=2;p!=1;j++)
   while(p%j==0)
   {
    p/=j;
    a[j]++;
   }
 }
 for(int i=2;i<=n;i++)
  if(a[i])
   if(first)
   {
    printf("%d^%d ",i,a[i]);
    first=0;
   }
   else printf("* %d^%d ",i,a[i]);
 return 0;
}
