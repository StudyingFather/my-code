#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
 scanf("%s",s);
 int first1=-1,len=strlen(s);
 for(int i=0;i<len;i++)
  if(s[i]=='1')
  {
   first1=i;
   break;
  }
 if(first1==-1)puts("no");
 else
 {
  int num0=0;
  for(int i=first1+1;i<len;i++)
   if(s[i]=='0')num0++;
  if(num0>=6)puts("yes");
  else puts("no");
 }
 return 0;
}
