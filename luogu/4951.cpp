#include <cstdio>
#include <algorithm>
#define eqs 1e-6
using namespace std;
struct edge
{
 int u,v;
 double w;
}e[10005];
struct node
{
 int u,v,c,t;
}p[10005];
int n,m,f;
bool cmp(const edge&a,const edge&b)
{
 return a.w>b.w;
}
int fa[505];
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
bool check(double l)
{
 for(int i=1;i<=m;i++)
 {
  e[i].u=p[i].u;
  e[i].v=p[i].v;
  e[i].w=-l*p[i].t-p[i].c;
 }
 for(int i=1;i<=n;i++)
  fa[i]=i;
 sort(e+1,e+m+1,cmp);
 int cnt=0;
 double sum=0;
 for(int i=1;;i++)
 {
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   cnt++;
   sum+=e[i].w;
   if(cnt==n-1)break;
  }
 }
 return sum>=-f;
}
int main()
{
 scanf("%d%d%d",&n,&m,&f);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d%d",&p[i].u,&p[i].v,&p[i].c,&p[i].t);
 double l=0,r=2e13;
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))l=mid;
  else r=mid;
 }
 printf("%.4lf\n",l);
 return 0;
}