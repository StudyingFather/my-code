#include <stdio.h>
int x0,y0,ans;
long long ji;
int gcd(int a,int b)
{
 return a%b?gcd(b,a%b):b;
}
int main()
{
 scanf("%d%d",&x0,&y0);
 ji=(long long)x0*y0;
 long long p=x0,q=y0;
 while(p<q)
 {
  if(p*q==ji)
   if(x0==gcd(p,q))ans+=2;
  p+=x0;
  q=ji/p;
 }
 if(x0==y0)ans++;
 printf("%d",ans);
 return 0;
}
