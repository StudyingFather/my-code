#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[10005];
int fa[105];
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
 fa[find(x)]=find(y);
}
int main()
{
 int n;
 while(~scanf("%d",&n))
 {
  int ans=0,cnt=0;
  memset(e,0,sizeof(e));
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
   {
    e[(i-1)*n+j].u=i,e[(i-1)*n+j].v=j;
    scanf("%d",&e[(i-1)*n+j].w);
   }
  for(int i=1;i<=n;i++)
   fa[i]=i;
  sort(e+1,e+n*n+1,cmp);
  for(int i=n+1;;i++)
   if(find(e[i].u)!=find(e[i].v))
   {
    unionn(e[i].u,e[i].v);
    ans+=e[i].w;
    cnt++;
    if(cnt==n-1)break;
   }
  printf("%d\n",ans);
 }
 return 0;
}
