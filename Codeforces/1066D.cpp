#include <stdio.h>
int a[200005];
int main()
{
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 for(int i=n;i>=1;i--)
  scanf("%d",&a[i]);
 int rem=m,used=0;
 for(int i=1;i<=n;i++)
 {
  if(used+a[i]>k)
  {
   rem--,used=a[i];
   if(rem==0)
   {
    printf("%d\n",i-1);
    return 0;
   }
  }
  else used+=a[i];
 }
 printf("%d\n",n);
 return 0;
}
