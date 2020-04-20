#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[35];
int len;
bool check(int d)
{
 int res=0,t=1;
 for(int i=1;i<=len;i++)
 {
  if(s[i]=='S')res+=t;
  else t<<=1;
 }
 return res<=d;
}
bool change()
{
 for(int i=len-1;i;i--)
  if(s[i]=='C'&&s[i+1]=='S')
  {
   swap(s[i],s[i+1]);
   return true;
  }
 return false;
}
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  int d,ans=0;
  scanf("%d",&d);
  scanf("%s",s+1);
  printf("Case #%d: ",kase);
  len=strlen(s+1);
  while(1)
  {
   if(check(d))
   {
    printf("%d\n",ans);
    break;
   }
   if(!change())
   {
    puts("IMPOSSIBLE");
    break;
   }
   ans++;
  }
 }
 return 0;
}