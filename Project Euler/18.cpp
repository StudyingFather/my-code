#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n=15,a[25][25],f[25][25],maxn;
int main()
{
 for(int i=1;i<=n;i++)
  for(int j=1;j<=i;j++)
   scanf("%d",&a[i][j]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=i;j++)
   f[i][j]=max(f[i-1][j]+a[i][j],f[i-1][j-1]+a[i][j]);
 for(int i=1;i<=n;i++)
  maxn=max(f[n][i],maxn);
 printf("%d\n",maxn);
 return 0;
}
