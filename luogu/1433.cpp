#include <cstdio>
#include <cmath>
struct point
{
 double x,y;
}p[25];
int vis[25],n;
double ans=1e100;
double calc(int a,int b)
{
 return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}
void dfs(int dep,int cur,double dist)
{
 if(dist>ans)return;
 if(dep==n)
 {
  ans=dist;
  return;
 }
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   vis[i]=1;
   dfs(dep+1,i,dist+calc(cur,i));
   vis[i]=0;
  }
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%lf%lf",&p[i].x,&p[i].y);
 dfs(0,0,0);
 printf("%.2lf\n",ans);
 return 0;
}