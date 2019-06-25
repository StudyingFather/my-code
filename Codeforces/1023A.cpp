#include <stdio.h>
char s1[200005],s2[200005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 scanf("%s",s1);
 scanf("%s",s2);
 int flag=1;
 for(int i=0;i<=n;i++)
  if(s1[i]=='*')
  {
   flag=-1;
   break;
  }
  else if(s1[i]=='?')continue;
  else if(s1[i]!=s2[i])
  {
   flag=0;
   break;
  }
 if(flag==1)puts("YES");
 else if(flag==0)puts("NO");
 else
 {
  for(int i=n-1,j=m-1;;i--,j--)
   if(s1[i]=='*')
   {
    if(i-1>j)flag=0;
    else flag=1;
    break;
   }
   else if(s1[i]=='?')continue;
   else if(s1[i]!=s2[j])
   {
    flag=0;
    break;
   }
  if(flag)puts("YES");
  else puts("NO");
 }
 return 0;
}
