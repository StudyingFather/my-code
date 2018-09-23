#include <stdio.h>
int main()
{
 int n,unh=0,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int a,b;
  scanf("%d%d",&a,&b);
  unh+=a+b-8;
  ans+=unh;
 }
 printf("%d",ans);
 return 0;
}
