#include <stdio.h>
int calc(int a)
{
 int num=0;
 while(a)
 {
  if(a%10==2)num++;
  a/=10;
 }
 return num;
}
int main()
{
 int l,r,ans=0;
 scanf("%d%d",&l,&r);
 for(int i=l;i<=r;i++)
  ans+=calc(i);
 printf("%d",ans);
 return 0;
}
