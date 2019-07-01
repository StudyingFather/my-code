#include <stdio.h>
int n,card[501][501],mx1,mx2,ans=0;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  for(int j=i+1;j<=n;j++)
  {
   scanf("%d",&card[i][j]);
   card[j][i]=card[i][j];
   card[i][i]=0;
  }
  for(int i=1;i<=n;i++)
  {
   mx1=mx2=0;
   for(int j=1;j<=n;j++)
   if(card[i][j]>mx1)mx2=mx1,mx1=card[i][j];
   else if(card[i][j]>mx2)mx2=card[i][j];
   if(mx2>ans)ans=mx2;
  }
 }
 printf("1\n%d",ans);
 return 0;
}
