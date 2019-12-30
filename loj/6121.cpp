#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int x,y,sit;
};
queue<node> q;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int dist[15][15][3005],f[15][15][15][15],g[15][15],vis[15][15][3005];
int main()
{
 int n,m,p,k,s;
 scanf("%d%d%d%d",&n,&m,&p,&k);
 memset(f,-1,sizeof(f));
 for(int i=1;i<=k;i++)
 {
  int x1,y1,x2,y2,g;
  scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
  f[x1][y1][x2][y2]=f[x2][y2][x1][y1]=1<<g;
 }
 scanf("%d",&s);
 for(int i=1;i<=s;i++)
 {
  int x,y,q;
  scanf("%d%d%d",&x,&y,&q);
  g[x][y]|=1<<q;
 }
 memset(dist,INF,sizeof(dist));
 q.push({1,1,g[1][1]});
 vis[1][1][g[1][1]]=1;
 dist[1][1][g[1][1]]=0;
 while(!q.empty())
 {
  int x=q.front().x,y=q.front().y,sit=q.front().sit;
  q.pop();
  vis[x][y][sit]=0;
  for(int i=0;i<4;i++)
  {
   int nx=x+dx[i],ny=y+dy[i];
   if(nx<=0||nx>n||ny<=0||ny>m)continue;
   if(f[x][y][nx][ny]==-1||(f[x][y][nx][ny]&sit))
    if(dist[nx][ny][sit|g[nx][ny]]>dist[x][y][sit]+1)
    {
     dist[nx][ny][sit|g[nx][ny]]=dist[x][y][sit]+1;
     if(!vis[nx][ny][sit|g[nx][ny]])
     {
      vis[nx][ny][sit|g[nx][ny]]=1;
      q.push({nx,ny,sit|g[nx][ny]});
     }
    }
  }
 }
 int ans=INF;
 for(int i=0;i<(1<<(p+1));i++)
  ans=min(ans,dist[n][m][i]);
 if(ans==INF)puts("-1");
 else printf("%d\n",ans);
 return 0;
}