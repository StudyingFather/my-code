#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int k[205],f[205][205];
int main()
{
 int n;
 while((~scanf("%d",&n))&&n)
 {
  memset(f,INF,sizeof(f));
  int a,b;
  scanf("%d%d",&a,&b);
  for(int i=1;i<=n;i++)
   f[i][i]=0;
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&k[i]);
   if(k[i]+i<=b)f[i][k[i]+i]=1;
   if(i-k[i]>=1)f[i][i-k[i]]=1;
  }
  for(int k=1;k<=n;k++)
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
     f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
  if(f[a][b]==INF)printf("-1");
  else printf("%d\n",f[a][b]);
 }
 return 0;
}
