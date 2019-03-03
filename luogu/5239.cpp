#include <stdio.h>
#define MOD 19260817
int f[1005][1005];
int main()
{
 int q;
 scanf("%d",&q);
 for(int i=1;i<=1000;i++)
  for(int j=1;j<=1000;j++)
   f[i][j]=(f[i-1][j-1]+f[i-1][j]+i)%MOD;
 while(q--)
 {
  int n,m;
  scanf("%d%d",&n,&m);
  printf("%d\n",f[m][n]);
 }
 return 0;
}
