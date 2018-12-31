#include <stdio.h>
#include <string.h>
#define MOD 1000000007
int h[10005],num;
char s[1505];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  memset(s,0,sizeof(s));
  scanf("%s",s);
  int hr=0,len=strlen(s);
  for(int i=0;i<len;i++)
   hr=(hr*6+s[i])%MOD;
  int flag=1;
  for(int i=1;i<=num;i++)
   if(hr==h[i])
   {
    flag=0;
    break;
   }
  if(flag)h[++num]=hr;
 }
 printf("%d",num);
 return 0;
}
