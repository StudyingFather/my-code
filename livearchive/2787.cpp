#include <stdio.h>
#include <string.h>
int num[105];
int main()
{
 int a,ans=0;
 while((~scanf("%d",&a))&&a!=-1)
 {
  ans=0;
  memset(num,0,sizeof(num));
  num[a]++;
  while((~scanf("%d",&a))&&a)
   num[a]++;
  for(int i=1;i<=50;i++)
   if(num[i]&&num[2*i])ans++;
  printf("%d\n",ans);
 }
 return 0;
}
