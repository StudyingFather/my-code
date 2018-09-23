#include <stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n/2;i++)
  printf("%d ",(n+1)/2+i);
 for(int i=1;i<=n-n/2;i++)
  printf("%d ",i);
 return 0;
}
