#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int fa[25],n;
double ans;
struct point
{
 int x,y;
}p[25];
struct edge
{
 int p,q;
 double s;
}e[205];
int find(int a)
{
 if(fa[a]==a)return a;
 return find(fa[a]);
}
void union_p(int a,int b)
{
 fa[b]=fa[a];
 return;
}
double dist(int a,int b)
{
 return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}
void calc_e()
{
 int id=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
  {
   e[id].p=i;
   e[id].q=j;
   e[id].s=dist(i,j);
   id++;
  }
 return;
}
int cmp(const edge&a,const edge&b)
{
 return a.s<b.s||(a.s==b.s&&(a.p<b.p||(a.p==b.p&&a.q<b.q)));
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p[i].x,&p[i].y);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 calc_e();
 sort(e+1,e+n*(n-1)/2+1,cmp);
 int k=0;
 for(int i=1;;i++)
 {
  if(find(e[i].p)!=find(e[i].q))
  {
   union_p(e[i].p,e[i].q);
   k++;
   ans+=e[i].s;
  }
  if(k==n-1)break;
 }
 printf("%.2lf",ans);
 return 0;
}
