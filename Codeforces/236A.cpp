#include <stdio.h>
int a[30],ans;
char c;
int main()
{
 while((c=getchar())!='\n')
  if(!a[c-96])
  {
   a[c-96]++;
   ans++;
  }
 printf("%s",ans%2?"IGNORE HIM!":"CHAT WITH HER!");
 return 0;
}
