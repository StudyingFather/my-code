#include <cstdio>
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
 int n,k,sum;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  fa[i]=i; 
 for(int i=1;i<=k;i++)
 {
  scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
  sum+=e[i].w;
 }
 sort(e+1,e+k+1,cmp);
 int cnt=0;
 for(int i=1;;i++)
 {
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(e[i].u,e[i].v);
   cnt++;
   sum-=e[i].w;
  }
  if(cnt==n-1)break;
 }
 printf("%d\n",sum);
 return 0;
}