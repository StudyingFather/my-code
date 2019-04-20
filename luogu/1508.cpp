#include <cstdio>
#include <algorithm>
using namespace std;
int a[205][205],f[205][205];
int main()
{
 int m,n;
 scanf("%d%d",&m,&n);
 int mid=n/2+1;
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
   f[i][j]=max(f[i-1][j-1],max(f[i-1][j],f[i-1][j+1]))+a[i][j];
 printf("%d\n",max(f[m][mid],max(f[m][mid-1],f[m][mid+1])));
 return 0;
}