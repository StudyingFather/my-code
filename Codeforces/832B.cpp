#include <stdio.h>
#include <string.h>
int g_l[35],n;
char g[35],s[100005],c[100005];
int main()
{
 scanf("%s",g);
 int lg=strlen(g);
 for(int i=0;i<lg;i++)
  g_l[g[i]-'a']++;
 scanf("%s",s);
 scanf("%d",&n);
 int ls=strlen(s);
 for(int t=1;t<=n;t++)
 {
  int flag=1;
  memset(c,0,sizeof(c));
  scanf("%s",c);
  int lc=strlen(c);
  int arr=0;
  for(int i=0;i<ls||arr<lc;i++)
  {
   if(c[arr]==s[i])
   	arr++;
   else if(s[i]=='?'&&g_l[c[arr]-'a'])
    arr++;
   else if(s[i]=='*')
   {
    for(;arr<lc;arr++)
     if(g_l[c[arr]-'a'])
      if(s[i+1]!=c[arr]&&s[i+1]!='?')
      {
       flag=0;
       break;
      }
      else break;
     else
     {
      if(lc<ls)break;
     }
   }
   else
   {
   	flag=0;
   	break;
   }
  }
  if(flag)printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}
