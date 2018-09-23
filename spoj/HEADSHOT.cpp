#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
 scanf("%s",s);
 int n=strlen(s),a=0,b=0;
 for(int i=0;i<n;i++)
 {
  if(s[i]=='0')b++;
  if(s[i]=='0'&&s[i+1]=='0')a++;
  if(i==n-1&&s[i]=='0'&&s[0]=='0')a++;
 }
 if(a*n>b*b)printf("SHOOT");
 else if(a*n<b*b)printf("ROTATE");
 else printf("EQUAL");
 return 0;
}
