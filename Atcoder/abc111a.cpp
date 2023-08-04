#include <stdio.h>
#include <string.h>
char s[5];
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  if(s[i]=='1')printf("9");
  else printf("1");
 return 0;
}