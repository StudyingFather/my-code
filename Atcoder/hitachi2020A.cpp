#include <cstdio>
#include <cstring>
char s[15];
int main()
{
 scanf("%s",s+1);
 int len=strlen(s+1);
 for(int i=1;i<=len;i+=2)
  if(s[i]!='h'||s[i+1]!='i')
  {
   puts("No");
   return 0;
  }
 puts("Yes");
 return 0;
}