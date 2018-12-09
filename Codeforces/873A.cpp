#include <stdio.h>
int main()
{
 int n,k,x,ans=0;
 scanf("%d%d%d",&n,&k,&x);
 for(int i=n;i>=1;i--)
 {
  int num;
  scanf("%d",&num);
  if(i<=k)ans+=x;
  else ans+=num;
 }
 printf("%d\n",ans);
 return 0;
} 
