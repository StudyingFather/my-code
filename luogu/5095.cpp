#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int x,t;
}a[1005];
int f[1005][1005][2],c,h,b;
bool cmp(const node&a,const node&b)
{
 return a.x<b.x;
}
int main()
{
 scanf("%d%d%d",&c,&h,&b);
 for(int i=1;i<=c;i++)
  scanf("%d%d",&a[i].x,&a[i].t);
 sort(a+1,a+c+1,cmp);
 memset(f,INF,sizeof(f));
 f[1][c][0]=max(a[1].x,a[1].t);
 f[1][c][1]=max(a[c].x,a[c].t);
 for(int i=1;i<=c;i++)
  for(int j=c;j>=i;j--)
  {
   f[i][j][0]=min(f[i][j][0],max(f[i-1][j][0]+a[i].x-a[i-1].x,a[i].t));
   f[i][j][0]=min(f[i][j][0],max(f[i][j+1][1]+a[j+1].x-a[i].x,a[i].t));
   f[i][j][1]=min(f[i][j][1],max(f[i-1][j][0]+a[j].x-a[i-1].x,a[j].t));
   f[i][j][1]=min(f[i][j][1],max(f[i][j+1][1]+a[j+1].x-a[j].x,a[j].t));
  }
 int ans=INF;
 for(int i=1;i<=c;i++)
  ans=min(ans,min(f[i][i][0],f[i][i][1])+abs(a[i].x-b));
 printf("%d\n",ans);
 return 0;
}
