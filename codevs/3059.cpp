#include <stdio.h>
int n,a,total,flag=1;
void yunfei(int a)
{
 if(a<=10)total+=50;
 else if(a<=100)total+=180;
 else if(a<=300)total+=300;
 else if(a<=1000)total+=1000;
 else if(a<=3000)total+=2000;
 else flag=0;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a);
  yunfei(a);
  if(!flag)
  {
   printf("Can't transport!");
   return 0;
  }
 }
 printf("%d",total);
 return 0;
}
