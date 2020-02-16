#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
 int u,v,w;
 bool operator<(const node&a)const
 {
  return w>a.w;
 }
}p[50005];
struct dsu
{
 int fa[20005];
 void init(int n)
 {
  for(int i=1;i<=n;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?x:fa[x]=find(fa[x]);
 }
 void set(int x,int y)
 {
  fa[x]=y;
 }
}d;
vector<int> e[20005];
int val[20005],fa[20005][25],dep[20005];
int n,m,cnt;
void build_retree()
{
 sort(p+1,p+m+1);
 cnt=n;
 d.init(2*n);
 for(int i=1;i<=m;i++)
 {
  int u=p[i].u,v=p[i].v;
  int fu=d.find(u),fv=d.find(v);
  if(fu!=fv)
  {
   cnt++;
   e[cnt].push_back(fu);
   e[cnt].push_back(fv);
   d.set(fu,cnt),d.set(fv,cnt);
   val[cnt]=p[i].w;
  }
 }
}
void dfs(int u,int f)
{
 dep[u]=dep[f]+1,fa[u][0]=f;
 for(int i=1;(1<<i)<=dep[u];i++)
  fa[u][i]=fa[fa[u][i-1]][i-1];
 for(auto v:e[u])
  dfs(v,u);
}
int lca(int x,int y)
{
 if(dep[x]>dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[y]-dep[x]>=(1<<i))
   y=fa[y][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
   x=fa[x][i],y=fa[y][i];
 return fa[x][0];
}
int main()
{
 cin>>n>>m;
 for(int i=1;i<=m;i++)
  cin>>p[i].u>>p[i].v>>p[i].w;
 build_retree();
 for(int i=1;i<=cnt;i++)
  if(d.find(i)==i)dfs(i,0);
 int q;
 cin>>q;
 while(q--)
 {
  int u,v;
  cin>>u>>v;
  if(d.find(u)!=d.find(v))cout<<-1<<endl;
  else cout<<val[lca(u,v)]<<endl;
 }
 return 0;
}