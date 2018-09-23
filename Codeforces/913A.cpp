#include <stdio.h>
#include <math.h>
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 if(n>30)printf("%d",m);
 else printf("%d",m%(int)pow(2,n));
 return 0;
}
