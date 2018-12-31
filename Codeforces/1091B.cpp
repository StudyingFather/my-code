#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
 int x,y;
}p1[1005],p2[1005];
bool cmp(const point&a,const point&b)
{
 return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p1[i].x,&p1[i].y);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p2[i].x,&p2[i].y);
 sort(p1+1,p1+n+1,cmp);
 sort(p2+1,p2+n+1,cmp);
 printf("%d %d\n",p1[1].x+p2[n].x,p1[1].y+p2[n].y);
 return 0;
}
