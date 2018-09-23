#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
  {
   if(s[i]=='n')continue;
   else if(s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u')continue;
   else
   {
   	printf("No");
   	return 0;
   }  
  }
 printf("Yes");
 return 0;
}
