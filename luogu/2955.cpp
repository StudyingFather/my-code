#include <stdio.h>
#include <string.h>
char s[65];
int n;
int main()
{
 scanf("%d",&n);
 while(n--)
 {
  scanf("%s",s);
  if(s[strlen(s)-1]%2)puts("odd");
  else puts("even");
 }
 return 0;
}
