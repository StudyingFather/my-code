#include <stdio.h>
int k,n,w;
int main()
{
 scanf("%d%d%d",&k,&n,&w);
 n=-n;
 for(int i=1;i<=w;i++)
  n+=i*k;
 printf("%d",n<0?0:n);
 return 0;
}
