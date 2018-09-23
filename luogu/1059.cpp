#include <stdio.h>
int a[1005],n,num,total;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&num);
  if(!a[num])
  {
   a[num]++;
   total++;
  }
 }
 printf("%d\n",total);
 for(int i=1;i<=1000;i++)
  if(a[i])printf("%d ",i);
 return 0;
}
