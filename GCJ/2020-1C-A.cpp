#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<char,int> dx,dy;
char s[1005];
int main()
{
 int t;
 scanf("%d",&t);
 dx['W']=-1,dx['E']=1;
 dy['S']=-1,dy['N']=1;
 for(int kase=1;kase<=t;kase++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  scanf("%s",s+1);
  int l=strlen(s+1);
  printf("Case #%d: ",kase);
  bool flag=false;
  for(int i=1;i<=l;i++)
  {
   x+=dx[s[i]],y+=dy[s[i]];
   if(abs(x)+abs(y)<=i)
   {
    printf("%d\n",i);
    flag=true;
    break;
   }
  }
  if(!flag)puts("IMPOSSIBLE");
 }
 return 0;
}