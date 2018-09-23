#include <stdio.h>
int a1,a2,ans;
int main()
{
 scanf("%d%d",&a1,&a2);
 while(a1>0&&a2>0)
 {
  if(a1==1&&a2==1)break;
  if(a1>a2||a2==1)
  {
   a1-=2;
   a2++;
  }
  else
  {
   a1++;
   a2-=2;
  }
  ans++;
 }
 printf("%d",ans);
 return 0;
}
