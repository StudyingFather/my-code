#include <stdio.h>
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,m;
  scanf("%d%d",&n,&m);
  if((n-(n-1)/m-1)&1)puts("0");
  else puts("1");
 }
 return 0;
}
