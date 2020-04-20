#include <cstdio>
#include <cstring>
#include <cmath>
double f[255][255],g[255],p[255];
int d[255];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  memset(f,0,sizeof(f));
  memset(g,0,sizeof(g));
  int n,r;
  scanf("%d%d",&n,&r);
  f[0][0]=1;
  for(int i=1;i<=n;i++)
   scanf("%lf%d",&p[i],&d[i]);
  for(int i=1;i<=n;i++)
   for(int j=0;j<=r;j++)
   {
    double tmp=pow(1-p[i],r-j);
    f[i][j]=f[i-1][j]*tmp+(j>0)*f[i-1][j-1]*(1-tmp*(1-p[i]));
   }
  g[1]=(1-pow(1-p[1],r));
  for(int i=2;i<=n;i++)
   for(int j=0;j<=r;j++)
    g[i]+=f[i-1][j]*(1-pow(1-p[i],r-j));
  double ans=0;
  for(int i=1;i<=n;i++)
   ans+=g[i]*d[i];
  printf("%.10lf\n",ans);
 }
 return 0;
}