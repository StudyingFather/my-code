#include <stdio.h>
int calc(int n)
{
 int ans=1;
 for(int i=1;i<=n/2;i++)
  ans+=calc(i);
 return ans;
}
int main()
{
 int n;
 scanf("%d",&n);
 printf("%d",calc(n));
 return 0;
}
