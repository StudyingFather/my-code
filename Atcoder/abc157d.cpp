#include <iostream>
using namespace std;
struct dsu
{
 int fa[100005],siz[100005];
 void init(int n)
 {
  for(int i=1;i<=n;i++)
   fa[i]=i,siz[i]=1;
 }
 int getsiz(int x)
 {
  x=find(x);
  return siz[x];
 }
 int find(int x)
 {
  return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
 }
 void merge(int x,int y)
 {
  x=find(x),y=find(y);
  if(x==y)return;
  fa[y]=x,siz[x]+=siz[y];
  siz[y]=0;
 }
}d;
int res[100005];
int main()
{
 int n,m,k;
 cin>>n>>m>>k;
 d.init(n);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  cin>>x>>y;
  d.merge(x,y);
  res[x]--,res[y]--;
 }
 for(int i=1;i<=n;i++)
  res[i]+=d.getsiz(i)-1;
 for(int i=1;i<=k;i++)
 {
  int x,y;
  cin>>x>>y;
  if(d.find(x)==d.find(y))
   res[x]--,res[y]--;
 }
 for(int i=1;i<=n;i++)
  cout<<res[i]<<' ';
 return 0;
}