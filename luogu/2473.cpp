#include <cstdio>
#include <algorithm>
using namespace std;
int v[105],s[25];
double f[105][60005];
int main()
{
 int k,n,maxs;
 scanf("%d%d",&k,&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&v[i]);
  while(1)
  {
   scanf("%d",&x);
   if(!x)break;
   s[i]|=1<<(x-1);
  }
 }
 maxs=(1<<n)-1;
 for(int i=k;i;i--)
  for(int j=0;j<=maxs;j++)
  {
   for(int k=1;k<=n;k++)
    if((s[k]&j)==s[k])
     f[i][j]+=max(f[i+1][j],f[i+1][j|(1<<(k-1))]+v[k]);
    else f[i][j]+=f[i+1][j];
   f[i][j]/=n;
  }
 printf("%.6lf\n",f[1][0]);
 return 0;
}