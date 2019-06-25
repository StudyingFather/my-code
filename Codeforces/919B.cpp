#include <stdio.h>
int num=19,k,top,rest=10;
int chai(int a)
{
 int r=0;
 while(a)
 {
  r+=a%10;
  a/=10;
 }
 return r;
}
int main()
{
 scanf("%d",&k);
 for(int i=2;i<=k;i++)
 {
  num+=9;
  if((num/100)!=top||chai(num%100)>rest)
  {
   top++;
   rest=10-chai(top);
   while(rest<0)
   {
    top++;
    rest=10-chai(top);
   }
   num=top*100+rest;
  }
 }
 printf("%d",num);
 return 0;
}
