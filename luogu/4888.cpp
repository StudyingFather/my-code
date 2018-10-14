#include <cstdio>
#include <algorithm>
using namespace std;
char s[2005][2005];
int main()
{
 int l,q;
 scanf("%d%d",&l,&q);
 for(int i=1;i<=l;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=q;i++)
 {
  int x,y,ans=1;
  scanf("%d%d",&x,&y);
  for(int i=1;y+i<=l&&y-i>0;i++)
   if(s[x][y-i]!=s[x][y+i])
   {
    ans=max(ans,2*(i-1)+1);
    break;
   }
   else if(y+i==l||y-i==1)
   {
    ans=max(ans,2*i+1);
    break;
   }
  for(int i=1;x+i<=l&&x-i>0;i++)
   if(s[x-i][y]!=s[x+i][y])
   {
    ans=max(ans,2*(i-1)+1);
    break;
   }
   else if(x+i==l||x-i==1)
   {
    ans=max(ans,2*i+1);
    break;
   }
  printf("%d\n",ans);
 }
 return 0;
}