#include <cstdio>
#include <algorithm>
using namespace std;
struct lukou
{
 int x,y,k;
}a[25];
int place[135][135];
int d,n,maxp;
int cmp(int a,int b)
{
 return a>b;
}
void fugai(int i)
{
 for(int x=(a[i].x-d>=0?a[i].x-d:0);x<=(a[i].x+d<=128?a[i].x+d:128);x++)
  for(int y=(a[i].y-d>=0?a[i].y-d:0);y<=(a[i].y+d<=128?a[i].y+d:128);y++)
  {
   place[x][y]+=a[i].k;
   maxp=max(maxp,place[x][y]);
  }
}
int main()
{
 scanf("%d%d",&d,&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].k);
  fugai(i);
 }
 int ans=0;
 for(int x=0;x<=128;x++)
  for(int y=0;y<=128;y++)
   if(place[x][y]==maxp)ans++;
 printf("%d %d",ans,maxp);
 return 0;
}