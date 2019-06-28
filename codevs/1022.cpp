#include <iostream>
#include <cstdio>
using namespace std;
int map[105][105],girl[105][105][2],used[105][105];
int n,m,k,t,ans;
bool find(int x,int y)
{
 int i,p[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
 for(i=0;i<4;i++)
  if(x+p[i][0]>0&&x+p[i][0]<=n&&y+p[i][1]>0&&y+p[i][1]<=m)
   if(map[x+p[i][0]][y+p[i][1]]!=1&&used[x+p[i][0]][y+p[i][1]]!=t)
   {
    used[x+p[i][0]][y+p[i][1]]=t;
    if(girl[x+p[i][0]][y+p[i][1]][0]==0||find(girl[x+p[i][0]][y+p[i][1]][0],girl[x+p[i][0]][y+p[i][1]][1]))
    {
     girl[x+p[i][0]][y+p[i][1]][0]=x;
     girl[x+p[i][0]][y+p[i][1]][1]=y;
     girl[x][y][0]=x+p[i][0];
     girl[x][y][1]=y+p[i][1];
     return true;
    }
   }
 return false;
}
int main()
{
 int i,j;
 scanf("%d%d%d",&n,&m,&k);
 for(i=1;i<=k;i++)
 {
  int a,b;
  scanf("%d%d",&a,&b);
  map[a][b]=1;
 }
 for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
  {
   if(girl[i][j][0]!=0||map[i][j]==1)continue;
   t++;
   if(find(i,j))
   ans++;
  }
 printf("%d\n",ans);
 return 0;
}
