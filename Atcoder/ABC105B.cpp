#include <stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=0;4*i<=n;i++)
  if((n-4*i)%7==0)
  {
   puts("Yes");
   return 0;
  }
 puts("No");
 return 0;
}
