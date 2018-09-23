#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int f[505][505],b[505][505],y[505][505];
int main()
{
 int n,m;
 while(~scanf("%d%d",&n,&m)&&n&&m)
 {
  memset(f,0,sizeof(f));
  memset(y,0,sizeof(y));
  memset(b,0,sizeof(b));
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   {
    scanf("%d",&y[i][j]);
    y[i][j]+=y[i][j-1];
   }
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   {
    scanf("%d",&b[i][j]);
    b[i][j]+=b[i-1][j];
   }
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    f[i][j]=max(f[i-1][j]+y[i][j],f[i][j-1]+b[i][j]);
  printf("%d\n",f[n][m]);
 }
 return 0;
}
