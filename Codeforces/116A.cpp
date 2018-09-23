#include <stdio.h>
int main()
{
 int a,b,maxn=0,n,num=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a,&b);
  num=num-a+b;
  maxn=num>maxn?num:maxn;
 }
 printf("%d",maxn);
 return 0;
}
