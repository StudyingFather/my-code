#include <cstdio>
#include <algorithm>
using namespace std;
int a[205][205],f[205][205];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   scanf("%d",&a[i][j]);
 f[1][2]=a[1][2]+a[2][1];
 for(int i=4;i<n+m;i++)
  for(int j=min(n,i-2);j;j--)
   for(int k=min(n,i-1);k>j;k--)
   {
    f[j][k]=max(f[j][k],max(f[j-1][k],f[j-1][k-1]));
    if(k-1>j)f[j][k]=max(f[j][k],f[j][k-1]);
    f[j][k]+=a[j][i-j]+a[k][i-k];
   }
 printf("%d\n",f[n-1][n]);
 return 0;
}