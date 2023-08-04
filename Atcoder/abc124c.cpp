#include <cstdio>
#include <cstring>
char s[100005];
int main()
{
 int ans=0;
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  s[i]-='0';
 for(int i=0;i<len-1;i++)
  if(s[i]==s[i+1])
  {
   s[i+1]=!s[i+1];
   ans++;
  }
 printf("%d\n",ans);
 return 0;
}