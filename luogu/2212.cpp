#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
 int x,y;
}p[2005];
struct edge
{
 int u,v,w;
}e[4000005];
int n,c,ans,cnt,tot,fa[2005];
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
 scanf("%d%d",&n,&c);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p[i].x,&p[i].y);
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
  {
   tot++;
   e[tot].u=i;
   e[tot].v=j;
   e[tot].w=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
  }
 sort(e+1,e+tot+1,cmp);
 for(int i=1;i<=n*(n-1)/2;i++)
  if(e[i].w>=c&&find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   ans+=e[i].w;
   cnt++;
   if(cnt==n-1)break;
  }
 if(cnt==n-1)printf("%d\n",ans);
 else puts("-1");
 return 0;
}
