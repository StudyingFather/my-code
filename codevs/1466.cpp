#include <stdio.h>
int is_run(int n)
{
 if(n%4==0&&(n%100!=0||n%400==0))return 1;
 return 0;
}
int main()
{
 int a;
 scanf("%d",&a);
 if(is_run(a))printf("366");
 else printf("365");
 return 0;
}
