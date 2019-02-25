#include <stdio.h>
int main()
{
 int n,r;
 scanf("%d%d",&n,&r);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  if(num>=r)puts("Good boi");
  else puts("Bad boi");
 }
 return 0;
}
