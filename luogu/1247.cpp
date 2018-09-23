#include <stdio.h>
int a[500005],sg;
int main()
{
 int k;
 scanf("%d",&k);
 for(int i=1;i<=k;i++)
 {
  scanf("%d",&a[i]);
  sg^=a[i];
 }
 if(sg==0)printf("lose");
 else
 {
  for(int i=1;i<=k;i++)
   if(a[i]>=(sg^a[i]))
   {
   	printf("%d %d\n",a[i]-(sg^a[i]),i);
   	a[i]=sg^a[i];
   	for(int j=1;j<=k;j++)
   	 printf("%d ",a[j]);
   	return 0;
   }
 }
}
