#include <stdio.h>
int n,a[55],b[55];
int main()
{
 scanf("%d",&n);
 int suma=0,sumb=0;
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]),suma+=a[i];
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]),sumb+=b[i];
 if(suma>=sumb)puts("Yes");
 else puts("No");
 return 0;
}
