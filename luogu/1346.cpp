#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int f[105][105];
int main()
{
 int n,a,b;
 scanf("%d%d%d",&n,&a,&b);
 memset(f,INF,sizeof(f));
 for(int i=1;i<=n;i++)
  f[i][i]=0;
 for(int i=1;i<=n;i++)
 {
  int k;
  scanf("%d",&k);
  for(int j=1;j<=k;j++)
  {
   int v;
   scanf("%d",&v);
   f[i][v]=(j==1)?0:1;
  }
 }
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
 printf("%d\n",f[a][b]==INF?-1:f[a][b]);
 return 0;
}