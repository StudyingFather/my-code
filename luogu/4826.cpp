#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[4000005];
int a[2005],fa[2005],cnte;
long long ans;
bool cmp(const edge&a,const edge&b)
{
 return a.w>b.w;
}
void addedge(int u,int v,int w)
{
 e[++cnte].u=u;
 e[cnte].v=v;
 e[cnte].w=w;
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   addedge(i,j,a[i]^a[j]);
 sort(e+1,e+cnte+1,cmp);
 int cntp=0;
 for(int i=1;;i++)
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   cntp++;
   ans+=e[i].w;
   if(cntp==n-1)break;
  }
 cout<<ans<<endl;
 return 0;
}