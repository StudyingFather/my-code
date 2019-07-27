#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[]={1,1,2,2,-1,-1,-2,-2};
const int dy[]={2,-2,1,-1,2,-2,1,-1};
struct node
{
 int x,y,p;
};
queue<node> q;
int res[405][405];
int main()
{
 int n,m,x,y;
 scanf("%d%d%d%d",&n,&m,&x,&y);
 memset(res,-1,sizeof(res));
 q.push({x,y,0});
 res[x][y]=0;
 while(!q.empty())
 {
  node u=q.front();
  q.pop();
  for(int i=0;i<8;i++)
  {
   int x=u.x+dx[i],y=u.y+dy[i];
   if(x>0&&x<=n&&y>0&&y<=m&&res[x][y]==-1)
   {
    res[x][y]=u.p+1;
    q.push({x,y,u.p+1});
   }
  }
 }
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   printf("%-5d",res[i][j]);
  puts("");
 }
 return 0;
}