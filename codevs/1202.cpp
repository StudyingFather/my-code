#include <stdio.h>
int ans,n,a;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a);
  ans+=a;
 }
 printf("%d",ans);
 return 0;
}
