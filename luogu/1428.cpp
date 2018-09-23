#include <stdio.h>
int a[105],b[105];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   if(a[i]>a[j])b[i]++;
 for(int i=1;i<=n;i++)
  printf("%d ",b[i]);
 return 0;
}
