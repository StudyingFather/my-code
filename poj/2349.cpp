#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct point
{
 int x,y;
}pt[505];
struct length
{
 int s,t;
 double len;
}l[200005];
int fa[505],cntl;
bool cmp(const length&a,const length&b)
{
 return a.len<b.len;
}
int find(int n)
{
 if(fa[n]==n)return n;
 return fa[n]=find(fa[n]);
}
void calc(int p)
{
 for(int i=1;i<=p;i++)
  for(int j=1;j<i;j++)
  {
   l[++cntl].len=sqrt((double)(pt[i].x-pt[j].x)*(pt[i].x-pt[j].x)+(pt[i].y-pt[j].y)*(pt[i].y-pt[j].y));
   l[cntl].s=i;
   l[cntl].t=j;
  }
}
void unionn(int s,int t)
{
 fa[find(s)]=find(t);
}
void init(int p)
{
 memset(l,0,sizeof(l));
 memset(pt,0,sizeof(pt));
 for(int i=1;i<=p;i++)
  fa[i]=i;
 cntl=0;
}
int main()
{
 int n;
 scanf("%d",&n);
 while(n--)
 {
  int s,p;
  scanf("%d%d",&s,&p);
  init(p);
  for(int i=1;i<=p;i++)
   scanf("%d%d",&pt[i].x,&pt[i].y);
  calc(p);
  sort(l+1,l+cntl+1,cmp);
  int cntp=0;
  double ans=0;
  for(int i=1;;i++)
  {
   if(find(l[i].s)!=find(l[i].t))
   {
    unionn(l[i].s,l[i].t);
    ans=l[i].len;
    cntp++;
    if(cntp+s==p)break;
   }
  }
  printf("%.2lf\n",ans);
 }
 return 0;
}
