#include <stdio.h>
#include <string.h>
char s[25];
int main()
{
 for(int i=1;i<=10;i++)
 {
  int ans=1;
  scanf("%s",s);
  for(int i=0;i<strlen(s);i++)
   if(s[i]=='T'||s[i]=='D'||s[i]=='L'||s[i]=='F')ans*=2;
  printf("%d\n",ans);
 }
 return 0;
}
