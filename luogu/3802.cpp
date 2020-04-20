#include <cstdio>
int a[15];
int main()
{
 int n=0;
 for(int i=1;i<=7;i++)
 {
  scanf("%d",&a[i]);
  n+=a[i];
 }
 double ans=5040.0*(n-6);
 if(n<7)
 {
  puts("0.000");
  return 0;
 }
 for(int i=1;i<=7;i++)
  ans*=1.0*a[i]/(n-i+1);
 printf("%.3lf\n",ans);
 return 0;
}