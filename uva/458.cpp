#include <stdio.h>
char a;
int main()
{
 while((a=getchar())!=EOF)
  printf("%c",a!='\n'?a-7:'\n');
 return 0;
}
