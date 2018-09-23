#include <stdio.h>
int main()
{
 int a,b,c,n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d%d",&a,&b,&c);
  if(a+b+c>=2)ans++;
 }
 printf("%d",ans);
 return 0;
}
