#include <stdio.h>
int main()
{
 int n,a,b,ans=0;
 scanf("%d",&n);
 while(n--)
 {
  scanf("%d%d",&a,&b);
  if(b-a>=2)ans++;
 }
 printf("%d",ans);
 return 0;
}
