#include <stdio.h>
int m,n;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n;
  scanf("%d",&n);
  int flag=0;
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&m);
   flag^=m;
  }
  if(!flag)puts("No");
  else puts("Yes");
 }
 return 0;
}
