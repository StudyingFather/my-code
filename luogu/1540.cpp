#include <stdio.h>
#include <string.h>
int a[101],m,n,sum,temp=1,i,j,wa;
int main()
{
 memset(a,-1,sizeof(a));
 scanf("%d%d",&m,&n);
 for(i=1;i<=n;i++)
 {
  scanf("%d",&wa);
  for(j=1;j<=m;j++)
   if(a[j]==wa)break;
  if(j>m)
  {
   sum++;
   a[temp]=wa;
   temp++;
   if(temp>m)temp=1;
  }
 }
 printf("%d",sum);
}