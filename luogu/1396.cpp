#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[200005];
int fa[10005];
bool cmp(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int find(int a)
{
 return a==fa[a]?a:fa[a]=find(fa[a]);
}
void unionn(int a,int b)
{
 fa[find(a)]=find(b);
}
int main()
{
 int n,m,s,t;
 scanf("%d%d%d%d",&n,&m,&s,&t);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 sort(e+1,e+m+1,cmp);
 int ans=0;
 for(int i=1;i<=m;i++)
 {
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(e[i].u,e[i].v);
   ans=e[i].w;
  }
  if(find(s)==find(t))break; 
 }
 printf("%d\n",ans);
 return 0;
}