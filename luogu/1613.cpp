#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int f[55][55],g[55][55][55];
int main()
{
 int n,m;
 memset(f,INF,sizeof(f));
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  f[x][y]=1;
  g[x][y][0]=1;
 }
 for(int k=1;k<=50;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    for(int l=1;l<=n;l++)
     if(g[i][j][k-1]&&g[j][l][k-1])
      f[i][l]=g[i][l][k]=1;
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
 printf("%d\n",f[1][n]);
 return 0;
}