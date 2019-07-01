#include <cstdio>
#include <algorithm>
using namespace std;
int a[355],f[45][45][45][45],t[5];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=m;i++)
 {
  int b;
  scanf("%d",&b);
  t[b]++;
 }
 f[0][0][0][0]=a[1];
 for(int i=0;i<=t[1];i++)
  for(int j=0;j<=t[2];j++)
   for(int k=0;k<=t[3];k++)
    for(int l=0;l<=t[4];l++)
    {
     int num=i+2*j+3*k+4*l+1;
     if(i)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+a[num]);
     if(j)f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+a[num]);
     if(k)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+a[num]);
     if(l)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+a[num]);
    }
 printf("%d\n",f[t[1]][t[2]][t[3]][t[4]]);
 return 0;
}
