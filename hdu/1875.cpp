#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct edge
{
 int u,v;
 double w;
}e[5005];
struct point
{
 int x,y;
}p[105];
int fa[105],cnt;
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[find(x)]=find(y);
}
bool cmp(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int c;
void calc_dist()
{
 for(int i=1;i<=c;i++)
  for(int j=i+1;j<=c;j++)
  {
   e[++cnt].u=i;
   e[cnt].v=j;
   e[cnt].w=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
  }
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  cnt=0;
  memset(e,0,sizeof(e));
  memset(p,0,sizeof(p));
  memset(fa,0,sizeof(fa));
  scanf("%d",&c);
  for(int i=1;i<=c;i++)
   fa[i]=i;
  for(int i=1;i<=c;i++)
   scanf("%d%d",&p[i].x,&p[i].y);
  calc_dist();
  sort(e+1,e+cnt+1,cmp);
  int tot=0;
  double ans=0;
  for(int i=1;i<=cnt;i++)
  {
   if(e[i].w<10)continue;
   if(e[i].w>1000)break;
   if(find(e[i].u)!=find(e[i].v))
   {
    unionn(e[i].u,e[i].v);
    tot++;
    ans+=e[i].w;
   }
   if(tot==c-1)break;
  }
  if(tot==c-1)printf("%.1lf\n",ans*100);
  else puts("oh!");
 }
 return 0;
}
