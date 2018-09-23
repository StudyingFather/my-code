#include <stdio.h>
int m,n;
int main()
{
 while(~scanf("%d",&m))
 {
  int flag=0;
  for(int i=1;i<=m;i++)
  {
   scanf("%d",&n);
   flag^=n;
  }
  if(!flag)puts("No");
  else puts("Yes");
 }
 return 0;
}
