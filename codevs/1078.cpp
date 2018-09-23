#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int s,t,w;
}e[10005];
int cmp(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int fa[105],n,arr;
int find(int a)
{
 return fa[a]==a?a:find(fa[a]);
}
void uunion(int a,int b)
{
 int ra=find(a),rb=find(b);
 fa[rb]=ra;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   int w;
   scanf("%d",&w);
   if(i<j)
   {
    e[++arr].s=i;
    e[arr].t=j;
    e[arr].w=w;
   }
  }
 sort(e+1,e+arr+1,cmp);
 int ans=0,k=0; 
 for(int i=1;i<=arr;i++)
 {
  if(find(e[i].s)!=find(e[i].t))
  {
   uunion(e[i].s,e[i].t);
   ans+=e[i].w;
   k++;
  }
  if(k==n-1)
  {
   printf("%d",ans);
   return 0;
  }
 }
}
