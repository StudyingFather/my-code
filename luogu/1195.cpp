#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[10005];
int fa[1005];
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
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
 sort(e+1,e+m+1,cmp);
 int cnt=0,ans=0;
 for(int i=1;i<=m;i++)
 {
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(e[i].u,e[i].v);
   ans+=e[i].w;
   cnt++;
  }
  if(cnt==n-k)break; 
 }
 if(cnt!=n-k)puts("No answer");
 else printf("%d",ans);
 return 0;
}