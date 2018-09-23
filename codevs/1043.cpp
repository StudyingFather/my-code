#include <cstdio>
#include <algorithm>
using namespace std;
int map[15][15],n,f[15][15][15][15];
int main()
{
 scanf("%d",&n);
 int x=1,y=1,z=1;
 while(x!=0&&y!=0&&z!=0)
 {
  scanf("%d%d%d",&x,&y,&z);
  map[x][y]=z;
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   for(int k=1;k<=n;k++)
    for(int l=1;l<=n;l++)
    {
     f[i][j][k][l]=max(f[i-1][j][k-1][l],max(f[i][j-1][k-1][l],max(f[i-1][j][k][l-1],f[i][j-1][k][l-1])))+map[i][j]+map[k][l];
     if(i==k&&j==l)f[i][j][k][l]-=map[i][j];
    }
 printf("%d",f[n][n][n][n]);
 return 0;
}
