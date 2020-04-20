#include <cstdio>
char s[15];
int main()
{
 scanf("%s",s+1);
 if(s[3]==s[4]&&s[5]==s[6])
  puts("Yes");
 else puts("No");
 return 0;
}