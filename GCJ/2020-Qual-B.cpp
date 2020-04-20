#include <cstdio>
#include <cstring>
char s[105],t[10005];
int cnt=0;
void addl(int x)
{
 while(x--)
  t[++cnt]='(';
}
void addr(int x)
{
 while(x--)
  t[++cnt]=')';
}
void add(char c)
{
 t[++cnt]=c+'0';
}
int main()
{
 int T;
 scanf("%d",&T);
 for(int kase=1;kase<=T;kase++)
 {
  memset(t,0,sizeof(t));
  cnt=0;
  scanf("%s",s+1);
  int len=strlen(s+1),lastt=0;
  for(int i=1;i<=len;i++)
   s[i]-='0';
  for(int i=1;i<=len;i++)
  {
   int d=s[i]-lastt;
   if(d>0)addl(s[i]-lastt);
   else if(d<0)addr(lastt-s[i]);
   add(s[i]);
   lastt=s[i];
  }
  if(lastt)addr(lastt);
  printf("Case #%d: %s\n",kase,t+1);
 }
 return 0;
}