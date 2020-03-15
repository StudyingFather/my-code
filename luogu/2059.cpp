#include <cstdio>
double f[55][55];
int a[55];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
  scanf("%d",&a[i]);
 f[1][1]=1;
 for(int i=2;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   int p=(a[j]%i==0)?i:a[j]%i;
   for(int k=1;k<i;k++)
   {
    p++;
    if(p>i)p=1;
    f[i][p]+=f[i-1][k]/m;
   }
  }
 for(int i=1;i<=n;i++)
  printf("%.2lf%% ",f[n][i]*100);
 return 0;
}