#include <stdio.h>
int num[1005];
int main()
{
 int n;
 while((~scanf("%d",&n))&&n)
 {
  int ans=0,sum=0;
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&num[i]);
   sum^=num[i];
  }
  for(int i=1;i<=n;i++)
   if((sum^num[i])<num[i])ans++;
  printf("%d\n",ans);
 }
 return 0;
}
