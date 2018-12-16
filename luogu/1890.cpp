#include <stdio.h>
int a[1005],f[1005][1005];
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  f[i][i]=a[i];
 for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
   f[i][j]=gcd(f[i][j-1],a[j]);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  printf("%d\n",f[x][y]);
 }
 return 0;
}
