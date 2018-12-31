#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[100005];
int cnt,cntc,ans,fa[305];
void addedge(int u,int v,int w)
{
 e[++cnt].u=u;
 e[cnt].v=v;
 e[cnt].w=w;
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
 fa[x]=y;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
 {
  int w;
  scanf("%d",&w);
  addedge(0,i,w);
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   int w;
   scanf("%d",&w);
   addedge(i,j,w);
  }
 sort(e+1,e+cnt+1,cmp);
 for(int i=1;;i++)
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   ans+=e[i].w;
   cntc++;
   if(cntc==n)break;
  }
 printf("%d\n",ans);
 return 0;
}
