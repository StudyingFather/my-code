#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[500005];
int fa[200005];
long long ans;
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
 fa[x]=y;
}
int main()
{
 int n,m,cnt=0;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
  cin>>e[i].u>>e[i].v>>e[i].w;
 sort(e+1,e+m+1,cmp);
 for(int i=1;i<=m;i++)
 {
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   ans+=e[i].w;
   cnt++;
   if(cnt==n-1)break;
  }
 }
 cout<<ans<<endl;
 return 0;
}