#include <stdio.h>
double jisuan(int a)
{
 return 1.0/a;
}
int n,i;
double ans;
int main()
{
 scanf("%d",&n);
 for(i=1;ans<=n;i++)
  ans+=jisuan(i);
 printf("%d",i-1);
 return 0;
}
