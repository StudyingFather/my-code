#include <stdio.h>
int f[60][270005];
int main()
{
 int n,ans;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  f[x][i]=i+1;
 }
 for(int i=2;i<=58;i++)
  for(int j=1;j<=n;j++)
  {
   if(!f[i][j])f[i][j]=f[i-1][f[i-1][j]];
   if(f[i][j])ans=i;
  }
 printf("%d\n",ans);
 return 0;
}