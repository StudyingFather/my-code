#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int x,y,val;
};
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int ma[105][105],dist[105][105][15],vis[105][105][15];
queue<node> q;
int main()
{
 int n,k,a,b,c;
 scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&ma[i][j]);
 memset(dist,INF,sizeof(dist));
 dist[1][1][k]=0,vis[1][1][k]=1;
 q.push({1,1,k});
 while(!q.empty())
 {
  int x=q.front().x,y=q.front().y,val=q.front().val;
  q.pop();
  vis[x][y][val]=0;
  for(int i=0;i<4;i++)
  {
   int nx=x+dx[i],ny=y+dy[i],p=0,nv=val-1;
   if(nx<=0||nx>n||ny<=0||ny>n)continue;
   if(nx<x||ny<y)p+=b;
   if(ma[nx][ny])p+=a,nv=k;
   if(nv<=0&&(!ma[nx][ny]))
    if(nx!=n||ny!=n)
     p+=a+c,nv=k;
   if(dist[nx][ny][nv]>dist[x][y][val]+p)
   {
    dist[nx][ny][nv]=dist[x][y][val]+p;
    if(!vis[nx][ny][nv])
    {
     vis[nx][ny][nv]=1;
     q.push({nx,ny,nv});
    }
   }
  }
 }
 int ans=INF;
 for(int i=0;i<k;i++)
  ans=min(ans,dist[n][n][i]);
 printf("%d\n",ans);
 return 0;
}