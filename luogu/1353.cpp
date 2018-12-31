#include <cstdio>
#include <algorithm>
using namespace std;
int d[10005],f[100005][505];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&d[i]);
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=min(i,m);j++)
   f[i][0]=max(f[i][0],f[i-j][j]);
  f[i][0]=max(f[i][0],f[i-1][0]);
  for(int j=1;j<=min(i,m);j++)
   f[i][j]=max(f[i-1][j-1]+d[i],f[i][j]);
 }
 printf("%d\n",f[n][0]);
 return 0;
}
