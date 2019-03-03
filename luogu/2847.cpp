#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int x,y;
}p[1005];
struct edge
{
 int u,v,w;
}e[1000005];
int cnte,cntp,fa[1005];
void addedge(int x,int y)
{
 e[++cnte].u=x;
 e[cnte].v=y;
 e[cnte].w=(p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y);
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
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p[i].x,&p[i].y);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   addedge(i,j);
 sort(e+1,e+cnte+1,cmp);
 for(int i=1;;i++)
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   cntp++;
   ans=e[i].w;
   if(cntp==n-1)break;
  }
 printf("%d\n",ans);
 return 0;
}
