#include <stdio.h>
int main()
{
 int minn=105,n,k,ans=0;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  if(num<=0)break;
  if(i>k&&minn>num)break;
  ans++;
  minn=num;
 }
 printf("%d",ans);
 return 0;
}
