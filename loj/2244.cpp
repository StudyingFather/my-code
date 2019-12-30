#include <stdio.h>
char s[5];
int x1=0,x2=-1,x,ans;
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%s%d",s,&x);
  if(s[0]=='A')x1&=x,x2&=x;
  if(s[0]=='O')x1|=x,x2|=x;
  if(s[0]=='X')x1^=x,x2^=x;
 }
 for(int i=30;i>=0;i--)
  if(x1&(1<<i))ans+=(1<<i);
  else if((x2&(1<<i))&&(1<<i)<=m)ans+=1<<i,m-=1<<i;
 printf("%d\n",ans);
 return 0;
}