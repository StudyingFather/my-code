#include <stdio.h>
char s[1005],t[1005];
int n,m,times[1005];
void compare()
{
 for(int i=1;i<=m-n+1;i++)
  for(int j=1;j<=n;j++)
   if(s[j]!=t[i+j-1]&&s[j]!='?')times[i]++;
}
void find_answer()
{
 int minans=10000,place;
 for(int i=1;i<=m-n+1;i++)
  if(times[i]<minans)
  {
   minans=times[i];
   place=i;
  }
 printf("%d\n",minans);
 for(int j=1;j<=n;j++)
  if(s[j]!=t[place+j-1]&&s[j]!='?')
   printf("%d ",j);
}
int main()
{
 scanf("%d%d",&n,&m);
 scanf("%s%s",s+1,t+1);
 compare();
 find_answer();
 return 0;
}
