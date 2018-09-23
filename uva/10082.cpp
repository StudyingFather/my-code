#include <stdio.h>
const char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
 char c;
 while((c=getchar())!=EOF)
 {
  int flag=1;
  for(int i=1;i<=47;i++)
   if(s[i]==c)
   {
   	flag=0;
   	putchar(s[i-1]);
   	break;
   }
  if(flag)putchar(c);
 }
 return 0;
}
