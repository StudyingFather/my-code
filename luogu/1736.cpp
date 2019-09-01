#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[2505][2505],f[2505][2505],g[2505][2505],h[2505][2505];
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   scanf("%d",&a[i][j]);
   if(!a[i][j])
   {
    g[i][j]=g[i][j-1]+1;
    h[i][j]=h[i-1][j]+1;
   }
   else f[i][j]=min(f[i-1][j-1],min(g[i][j-1],h[i-1][j]))+1;
   ans=max(ans,f[i][j]);
  }
 memset(f,0,sizeof(f));
 memset(g,0,sizeof(g));
 memset(h,0,sizeof(h));
 for(int i=1;i<=n;i++)
  for(int j=m;j;j--)
  {
   if(!a[i][j])
   {
    g[i][j]=g[i][j+1]+1;
    h[i][j]=h[i-1][j]+1;
   }
   else f[i][j]=min(f[i-1][j+1],min(g[i][j+1],h[i-1][j]))+1;
   ans=max(ans,f[i][j]);
  }
 printf("%d\n",ans);
 return 0;
}