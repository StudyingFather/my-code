#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int a[105][105],f[105][105],r,c;
int dfs(int x,int y)
{
 if(f[x][y])return f[x][y];
 int ans=1;
 for(int i=0;i<=3;i++)
 {
  int tx=x+dx[i],ty=y+dy[i];
  if(tx>=1&&ty>=1&&tx<=r&&ty<=c&&a[x][y]>a[tx][ty])ans=max(ans,dfs(tx,ty)+1);
 }
 return f[x][y]=ans;
}
int main()
{
 int ans=1;
 scanf("%d%d",&r,&c);
 for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++)
   scanf("%d",&a[i][j]);
 for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++)
   ans=max(ans,dfs(i,j));
 printf("%d\n",ans);
 return 0;
}