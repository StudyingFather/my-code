#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,p[1001],v[1001],f[1001][1001];
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
  scanf("%d%d",&v[i],&p[i]);
 for(int i=1;i<=m;i++)
  for(int j=n;j>=0;j--)
   if(v[i]<j)f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+p[i]*v[i]);
   else f[i][j]=f[i-1][j];
 printf("%d",f[m][n]);
 return 0;
}
