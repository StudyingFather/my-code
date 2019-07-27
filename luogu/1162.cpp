#include <cstdio>
#include <queue>
using namespace std;
struct point
{
 int x,y;
};
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
queue<point> q;
int a[35][35],n,flag;
void dfs(int x,int y)
{
 q.push({x,y}),a[x][y]=0;
 if(x==1||x==n||y==1||y==n)flag=0;
 for(int i=0;i<4;i++)
  if(a[x+dx[i]][y+dy[i]]==-1)dfs(x+dx[i],y+dy[i]);
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
   if(!a[i][j])a[i][j]=-1;
  }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(a[i][j]==-1)
   {
    flag=2;
    dfs(i,j);
    while(!q.empty())
    {
     point p=q.front();
     q.pop();
     a[p.x][p.y]=flag;
    }
   }
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
   printf("%d ",a[i][j]);
  puts("");
 }
 return 0;
}