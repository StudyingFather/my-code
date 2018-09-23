#include <stdio.h>
#define k 1000000
int main()
{
 long double sum,num;
 while(~scanf("%Lf",&num))
  sum+=num*k;
 printf("%.5Lf",sum/k);
 return 0;
}
