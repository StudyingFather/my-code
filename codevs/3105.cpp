#include <stdio.h>
char a;
int l,r,n,ans;
int main()
{
 scanf("%d %c",&n,&a);
 a-=64;
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&l,&r);
  if(l>=a&&l<=r)ans++;
 }
 printf("%d",ans);
 return 0;
}
