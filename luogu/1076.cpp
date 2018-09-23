#include <stdio.h>
int a[10001][100],b[10001][100],c[10001];
int main()
{
 int n,m,i,j,t,s,x,ans=0;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
  for(j=0;j<m;j++)
  {
   scanf("%d%d",&a[i][j],&b[i][j]);
   if(a[i][j])c[i]++;
  }
 scanf("%d",&t);
 for(i=1;i<=n;i++)
 {
  ans=(ans+b[i][t])%20123;
  s=(b[i][t]-1)%c[i]+1;
  if(a[i][t])x=1;
  else x=0;
  while(x<s)
  {
   if(t==m-1)t=0;
   else t++;
   if(a[i][t])x++;
  }
 }
 printf("%d\n",ans);
 return 0;
}
