#include <cstdio>
#include <algorithm>
using namespace std;
int f[105][105];
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   int x;
   scanf("%d",&x);
   if(x)
   {
    f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
    ans=max(ans,f[i][j]);
   }
  }
 printf("%d\n",ans);
 return 0;
}