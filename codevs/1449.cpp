#include <stdio.h>
int f(int n)
{
 int ans=1;
 for(int i=1;i<=n;i++)
  ans*=i;
 return ans;
}
int main()
{
 int n;
 scanf("%d",&n);
 printf("%d",f(n));
 return 0;
}
