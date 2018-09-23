#include <stdio.h>
int t,ans,n;
int main()
{
 scanf("%d",&t);
 for(int i=1;i<=t;i++)
 {
  scanf("%d",&n);
  if(n>0)ans+=n;
 }
 printf("%d",ans);
 return 0;
}
