#include <cstdio>
#include <cstring>
char s[1005];
int t[5];
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  if(s[i]=='N')t[1]=1;
  else if(s[i]=='S')t[2]=1;
  else if(s[i]=='W')t[3]=1;
  else t[4]=1;
 if((t[1]^t[2])||(t[3]^t[4]))puts("No");
 else puts("Yes");
 return 0;
}