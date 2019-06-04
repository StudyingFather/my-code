#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int sx,sy,tx,ty,ans,vis[15][15],n,m,t;
void dfs(int x,int y)
{
 vis[x][y]=1;
 if(x==tx&&y==ty)
 {
  ans++;
  vis[x][y]=0;
  return;
 }
 for(int i=0;i<=3;i++)
  if(x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=m&&(!vis[x+dx[i]][y+dy[i]]))
   dfs(x+dx[i],y+dy[i]);
 vis[x][y]=0;
}
int main()
{
 scanf("%d%d%d",&n,&m,&t);
 scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
 for(int i=1;i<=t;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  vis[x][y]=1;
 }
 dfs(sx,sy);
 printf("%d\n",ans);
 return 0;
}