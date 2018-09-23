#include <stdio.h>
int calc(int a,int b)
{
 int ans=0;
 while(a)
 {
  if(a%10==b)ans++;
  a/=10;
 }
 return ans;
}
int main()
{
 int x,y,ans;
 scanf("%d%d",&x,&y);
 for(int i=1;i<=x;i++)
  ans+=calc(i,y);
 printf("%d",ans);
 return 0;
}
