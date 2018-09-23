#include <stdio.h>
#include <math.h>
#define e 2.71828182845 
int x,y;
int main()
{
 scanf("%d%d",&x,&y);
 long double ans1=log(x)/x,ans2=log(y)/y;
 if(ans1==ans2)puts("=");
 else if(ans1>ans2)puts(">");
 else puts("<");
 return 0;
}
