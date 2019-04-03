#include <stdio.h>
int main()
{
 int n,sum=0;
 scanf("%d",&n);
 while(n)
 {
  sum+=n%10;
  n/=10;
 }
 if(sum%5==0)puts("YES");
 else puts("NO");
 return 0;
}