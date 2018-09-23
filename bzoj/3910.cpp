#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 501000
#define LOGN 20
using namespace std;
struct Eli
{
 int v,next;
}e[N<<1];
int head[N],cnt;
inline void add(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int n,m,root;
int dep[N],fa[N][LOGN];
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
int f[N];
int find(int x)
{
 return f[x]==x?x:f[x]=find(f[x]);
}
void array()
{
 for(int i=1;i<=n;i++)
  f[i]=i;
 for(int j=1;j<LOGN;j++)
  for(int i=1;i<=n;i++)
   fa[i][j]=fa[fa[i][j-1]][j-1];
}
int getlca(int &ans,int x,int y)
{
 ans=0;
 int i;
 if(dep[x]<dep[y])swap(x,y);
 for(i=LOGN-1;~i;i--)
  if(dep[fa[x][i]]>=dep[y])ans+=1<<i,x=fa[x][i];
 if(x==y)return x;
 for(i=LOGN-1;~i;i--)
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
 dfs(1,0),array();
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
