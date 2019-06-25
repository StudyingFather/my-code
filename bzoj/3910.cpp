#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Eli
{
 int v,next;
}e[1000005];
int head[500005],cnt;
inline void add(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int n,m,root;
int dep[500005],fa[500005][25];
void dfs(int x,int p)
{
 int i,v;
 dep[x]=dep[p]+1;
 for(i=head[x];i;i=e[i].next)
 {
  v=e[i].v;
  if(v==p)continue;
  fa[v][0]=x;
  dfs(v,x);
 }
}
int f[500005];
int find(int x)
{
 return f[x]==x?x:f[x]=find(f[x]);
}
void init()
{
 for(int i=1;i<=n;i++)
  f[i]=i;
 for(int j=1;j<25;j++)
  for(int i=1;i<=n;i++)
   fa[i][j]=fa[fa[i][j-1]][j-1];
}
int getlca(int &ans,int x,int y)
{
 ans=0;
 int i;
 if(dep[x]<dep[y])swap(x,y);
 for(i=24;~i;i--)
  if(dep[fa[x][i]]>=dep[y])ans+=1<<i,x=fa[x][i];
 if(x==y)return x;
 for(i=24;~i;i--)
  if(fa[x][i]!=fa[y][i])ans+=1<<(i+1),x=fa[x][i],y=fa[y][i];
 ans+=2;
 return fa[x][0];
}
int main()
{
 int i;
 int a,b,c;
 scanf("%d%d%d",&n,&m,&root);
 for(i=1;i<n;i++)
 {
  scanf("%d%d",&a,&b);
  add(a,b),add(b,a);
 }
 dfs(1,0),init();
 long long ans=0;
 for(int pos=root;m--;)
 {
  scanf("%d",&a);
  if(find(a)!=a)continue; 
  int lca=getlca(c,a,pos);
  ans+=c;
  int x=find(a),y=find(pos);
  while(x!=y)
  {
   if(dep[x]<dep[y])swap(x,y);
   x=f[x]=find(fa[x][0]);
  }
  if(find(lca)==lca)f[lca]=fa[lca][0];
  pos=a;
 }
 cout<<ans<<endl;
 return 0;
}
