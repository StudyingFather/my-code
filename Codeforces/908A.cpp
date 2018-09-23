#include <stdio.h>
#include <string.h>
char s[55];
int main()
{
 int len,ans=0;
 scanf("%s",s);
 len=strlen(s);
 for(int i=0;i<len;i++)
 {
  char c=s[i];
  if(c>='0'&&c<='9')
  {
   int num=c-'0';
   if(num%2)ans++;
  }
  else if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')ans++;
 }
 printf("%d",ans);
 return 0;
}
