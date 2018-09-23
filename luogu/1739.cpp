#include <stdio.h>
char s[305];
int cnt;
int main()
{
 scanf("%s",s);
 for(int i=0;;i++)
  if(s[i]=='@')
  {
   if(cnt==0)printf("YES");
   else printf("NO");
   break;
  }
  else if(s[i]=='(')cnt++;
  else if(s[i]==')')
  {
   cnt--;
   if(cnt<0)
   {
   	printf("NO");
   	break;
   }
  }
 return 0;
}
