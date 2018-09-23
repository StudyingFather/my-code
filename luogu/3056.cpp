#include <stdio.h>
#include <string.h>
char s[100005];
int cnt,ans;
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  if(s[i]=='(')cnt++;
  else if(s[i]==')'&&cnt>=1)cnt--;
  else ans++,cnt++;
 ans+=(cnt+1)/2;
 printf("%d",ans);
 return 0;
}
