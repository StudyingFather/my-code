#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
 scanf("%s",s);
 int len=strlen(s),n1=0,n2=0;
 for(int i=0;i<len;i++)
  if(s[i]=='o')n1++;
  else if(s[i]=='-')n2++;
 if(n1==0)printf("YES");
 else if(n2%n1==0)printf("YES");
 else printf("NO");
 return 0;
}
