/*
 Name: luogu P2872
 Author: StudyingFather
 Date: 2019/09/29 22:35
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
 int x,y;
}p[1005];
struct edge
{
 int u,v;
 double w;
}e[1000005];
int fa[1005],cnt;
void addedge(int u,int v,double w)
{
 e[++cnt].u=u;
 e[cnt].v=v;
 e[cnt].w=w;
}
double calc(double x1,double y1,double x2,double y2)
{
 return sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
}
bool cmp(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p[i].x,&p[i].y);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   addedge(i,j,calc(p[i].x,p[i].y,p[j].x,p[j].y));
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  addedge(x,y,0);
 }
 sort(e+1,e+cnt+1,cmp);
 double ans=0;
 int t=0;
 for(int i=1;i<=cnt;i++)
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   ans+=e[i].w;
   t++;
   if(t==n-1)break;
  }
 printf("%.2lf\n",ans);
 return 0;
}