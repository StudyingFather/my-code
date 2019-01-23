#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
 int x,y;
}po[505];
struct edge
{
 int u,v;
 double w;
}e[250005];
int fa[505];
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
 fa[x]=y;
}
int main()
{
 int s,p,cnte=0;
 double ans=0;
 scanf("%d%d",&s,&p);
 for(int i=1;i<=p;i++)
  fa[i]=i;
 for(int i=1;i<=p;i++)
  scanf("%d%d",&po[i].x,&po[i].y);
 for(int i=1;i<=p;i++)
  for(int j=1;j<i;j++)
  {
   e[++cnte].u=i;
   e[cnte].v=j;
   e[cnte].w=sqrt((po[i].x-po[j].x)*(po[i].x-po[j].x)+(po[i].y-po[j].y)*(po[i].y-po[j].y));
  }
 sort(e+1,e+cnte+1,cmp);
 int cnt=0;
 for(int i=1;;i++)
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   cnt++;
   ans=e[i].w;
   if(cnt==p-s)break;
  }
 printf("%.2lf\n",ans);
 return 0;
}
