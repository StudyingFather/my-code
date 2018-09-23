#include <cstdio>
#include <algorithm>
using namespace std;
char s[2005][2005];
int n,m,k,ans,em;
int main()
{
 scanf("%d%d%d",&n,&m,&k);
 getchar();
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
  {
   scanf("%c",&s[i][j]);
   if(s[i][j]=='.')em++;
   else
   {
    ans+=max(0,em-k+1);
    em=0;
   }
  }
  ans+=max(0,em-k+1);
  em=0;
  getchar();
 }
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)
   if(s[j][i]=='.')em++;
   else
   {
   	ans+=max(0,em-k+1);
   	em=0;
   }
  ans+=max(0,em-k+1);
  em=0;
 }
 printf("%d",k==1?ans/2:ans);
 return 0;
}
