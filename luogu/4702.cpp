#include <stdio.h>
int a[105],sum;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  sum+=a[i];
 }
 if(sum%2)puts("Alice");
 else puts("Bob");
 return 0;
}
