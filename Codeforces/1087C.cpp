#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
 int x,y;
}p[5];
int ma[1005][1005];
bool cmp(const point&a,const point&b)
{
 return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
bool no_person(int x,int y)
{
 for(int i=1;i<=3;i++)
  if(x==p[i].x&&y==p[i].y)return false;
 return true;
}
int main()
{
 int maxx=0,maxy=0,ans=0,minx=1005,miny=1005;
 for(int i=1;i<=3;i++)
 {
  scanf("%d%d",&p[i].y,&p[i].x);
  minx=min(minx,p[i].x);
  miny=min(miny,p[i].y);
  maxx=max(maxx,p[i].x);
  maxy=max(maxy,p[i].y);
  ma[p[i].x][p[i].y]++;
 }
 for(int i=1;i<=3;i++)
 {
  for(int j=minx;j<=maxx;j++)
   ma[j][p[i].y]++;
  for(int j=miny;j<=maxy;j++)
   ma[p[i].x][j]++;
 }
 for(int i=minx;i<=maxx;i++)
  for(int j=miny;j<=maxy;j++)
   if(ma[i][j]>=1&&no_person(i,j))
   {
    if(j>0&&ma[i][j]>=ma[i+1][j-1]&&no_person(i+1,j-1))ma[i+1][j-1]=0;
    else ma[i][j]=0;
    if(ma[i][j]>=ma[i+1][j+1]&&no_person(i+1,j+1))ma[i+1][j+1]=0;
    else ma[i][j]=0;
   }
 for(int i=minx;i<=maxx;i++)
  for(int j=miny;j<=maxy;j++)
   if(ma[i][j]>=1)ans++;
 printf("%d\n",ans);
 for(int i=minx;i<=maxx;i++)
  for(int j=miny;j<=maxy;j++)
   if(ma[i][j]>=1)printf("%d %d\n",j,i);
 return 0;
}
