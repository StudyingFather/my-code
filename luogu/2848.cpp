/*
 Name: luogu P2848
 Author: StudyingFather
 Date: 2019/10/05 23:16
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct point
{
 int x,y;
}p1[1005],p2[1005];
long long f[1005][1005][2];
int calc(int x1,int y1,int x2,int y2)
{
 return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main()
{
 int h,g;
 scanf("%d%d",&h,&g);
 for(int i=1;i<=h;i++)
  scanf("%d%d",&p1[i].x,&p1[i].y);
 for(int i=1;i<=g;i++)
  scanf("%d%d",&p2[i].x,&p2[i].y);
 memset(f,INF,sizeof(f));
 f[1][0][0]=0;
 for(int i=1;i<h;i++)
  for(int j=0;j<=g;j++)
  {
   f[i+1][j][0]=min(f[i+1][j][0],
                    min(f[i][j][1]+calc(p1[i+1].x,p1[i+1].y,p2[j].x,p2[j].y),
                        f[i][j][0]+calc(p1[i+1].x,p1[i+1].y,p1[i].x,p1[i].y)));
   if(j<g)
    f[i][j+1][1]=min(f[i][j+1][1],
                     min(f[i][j][1]+calc(p2[j+1].x,p2[j+1].y,p2[j].x,p2[j].y),
                         f[i][j][0]+calc(p2[j+1].x,p2[j+1].y,p1[i].x,p1[i].y)));
  }
 printf("%d\n",int(f[h][g][0]));
 return 0;
}