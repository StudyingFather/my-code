#include <stdio.h>
#define cw 4200
double f[3000005];
int main()
{
 int n;
 double ans;
 scanf("%d",&n);
 ans=f[1]=cw*100.0/n;
 for(int i=1;i<n;i++)
  f[i+1]=f[i]*(1-1.0/(2*i)),ans+=f[i+1];
 printf("%.2lf",ans);
 return 0;
}
