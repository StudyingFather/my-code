#include <stdio.h>
#include <string.h>
char s[105],a,b,c,first=1;
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  if(s[i]=='1')a++;
  else if(s[i]=='2')b++;
  else if(s[i]=='3')c++;
 if(a)first=0;
 for(int i=1;i<=a;i++)
  printf("%s",i==a?"1":"1+");
 if(b&&!first)
 {
  printf("+");
  first=0;
 }
 if(b)first=0;
 for(int i=1;i<=b;i++)
  printf("%s",i==b?"2":"2+");
 if(c&&!first)
 {
  printf("+");
  first=0;
 }
 if(c)first=0;
 for(int i=1;i<=c;i++)
  printf("%s",i==c?"3":"3+");
 return 0;
}
