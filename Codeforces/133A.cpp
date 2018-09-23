#include <stdio.h>
int main()
{
 char a;
 while((a=getchar())!='\n')
  if(a=='H'||a=='Q'||a=='9')
  {
   printf("YES");
   return 0;
  }
 printf("NO");
 return 0;
}
