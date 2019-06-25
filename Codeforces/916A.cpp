#include <stdio.h>
int main()
{
 int h,m,x,ans=0;
 scanf("%d",&x);
 scanf("%d%d",&h,&m);
 while(h%10!=7&&m%10!=7)
 {
  if(m>=x)m-=x;
  else
  {
   if(h!=0)
   {
    h--;
    m+=60;
    m-=x;
   }
   else
   {
    h=23;
    m+=60;
    m-=x;
   }
  }
  ans++;
 }
 printf("%d",ans);
 return 0;
}
