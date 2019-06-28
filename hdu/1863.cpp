#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[5005];
int fa[105];
bool cmp(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int find(int x)
{
 return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[find(y)]=find(x);
}
int main()
{
 int n;
 while(~scanf("%d",&n))
 {
  memset(e,0,sizeof(e));
  memset(fa,0,sizeof(fa));
  if(n==0)return 0;
  int m;
  scanf("%d",&m);
  for(int i=1;i<=m;i++)
   fa[i]=i;
  for(int i=1;i<=n;i++)
   scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
  sort(e+1,e+n+1,cmp);
  int cnt=0,ans=0;
  for(int i=1;i<=n;i++)
  {
   if(find(e[i].u)!=find(e[i].v))
   {
    unionn(e[i].u,e[i].v);
    cnt++;
    ans+=e[i].w;
   }
   if(cnt==m-1)break;
  }
  if(cnt==m-1)printf("%d\n",ans);
  else puts("?");
 }
 return 0;
}
