#include <stdio.h>
#include <string.h>
char s[105],t[105];
int main()
{
 scanf("%s",s);
 scanf("%s",t);
 if(strlen(s)!=strlen(t))puts("NO");
 else
 {
  int len=strlen(s);
  bool flag=true;
  for(int i=0;i<len;i++)
   if(s[i]!=t[len-i-1])
   {
   	flag=false;
   	break;
   }
  if(flag)puts("YES");
  else puts("NO");
 }
 return 0;
}
