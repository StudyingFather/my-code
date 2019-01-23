#include <cstdio>
#include <algorithm>
using namespace std;
int f[5005][5005];
int main()
{
 int n,r,ans=0;
 scanf("%d%d",&n,&r);
 for(int i=1;i<=n;i++)
 {
  int x,y,v;
  scanf("%d%d%d",&x,&y,&v);
  f[x+1][y+1]=v;
 }
 for(int i=1;i<=5001;i++)
  for(int j=1;j<=5001;j++)
   f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
 for(int i=r;i<=5000;i++)
  for(int j=r;j<=5000;j++)
   ans=max(ans,f[i-r][j-r]-f[i-r][j]-f[i][j-r]+f[i][j]);
 printf("%d\n",ans);
 return 0;
}