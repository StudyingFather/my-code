#include <stdio.h>
int h[10005];
int n,kase,a,b,ans;
int main()
{
 while(~scanf("%d",&n))
 {
  b=0;
  if(n==0)return 0;
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&h[i]);
   b+=h[i]; 
  }
  a=b/n;
  ans=0;
  for(int i=1;i<=n;i++)
  {
   if((h[i]-a)>=0)ans+=h[i]-a;
   else ans+=a-h[i];
  }
  ans=ans/2;
  printf("Set #%d\n",++kase);
  printf("The minimum number of moves is %d.\n\n",ans);
 }
 return 0;
}
