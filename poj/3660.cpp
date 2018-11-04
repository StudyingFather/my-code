#include <stdio.h>
int f[105][105];
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int a,b;
  scanf("%d%d",&a,&b);
  f[a][b]=1;
 }
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=f[i][j]|(f[i][k]&f[k][j]);
 for(int i=1;i<=n;i++)
 {
  int res=1;
  for(int j=1;j<=n;j++)
   if(i!=j)res&=(f[i][j]|f[j][i]);
  ans+=res;
 }
 printf("%d\n",ans);
 return 0;
}
