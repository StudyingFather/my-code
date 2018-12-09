#include <stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 printf("%.10lf\n",(double)n*(n+1)/2/(2*n-1));
 return 0;
}
