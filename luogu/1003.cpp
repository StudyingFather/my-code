#include <stdio.h>
int ditan[10005][5];
int main()
{
 int n,i,a,b,g,k,x,y;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  scanf("%d%d%d%d",&a,&b,&g,&k);
  ditan[i][1]=a;
  ditan[i][2]=a+g;
  ditan[i][3]=b;
  ditan[i][4]=b+k;
 }
 scanf("%d%d",&x,&y);
 for(i=n;i>=1;i--)
 {
  if(ditan[i][1]<=x&&ditan[i][2]>=x&&ditan[i][3]<=y&&ditan[i][4]>=y)
  {
   printf("%d",i);
   return 0;
  }
 }
 printf("-1");
 return 0;
}
