#include <stdio.h>
int acost,bcost;
double num;
int main()
{
 scanf("%d%lf",&acost,&num);
 bcost=acost*(num/10);
 printf("%d",(bcost+5)/10*10);
 return 0;
}
