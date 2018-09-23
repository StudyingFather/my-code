#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int n,q,cnt;
int deep[500001],head[500001],fa[500001][20];
bool vis[500001];
struct data
{
 int to,next;
}e[1000001];
void ins(int u,int v)
{
 e[++cnt].to=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void insert(int u,int v)
{
 ins(u,v);
 ins(v,u);
}
void dfs(int x)
{
 vis[x]=1;
 for(int i=1;i<=18;i++)
 {
  if(deep[x]<(1<<i))break;
  fa[x][i]=fa[fa[x][i-1]][i-1];
 }
 for(int i=head[x];i;i=e[i].next)
 {
  if(vis[e[i].to])continue;
  deep[e[i].to]=deep[x]+1;
  fa[e[i].to][0]=x;
  dfs(e[i].to);
 }
}
int lca(int x,int y)
{
 if(deep[x]<deep[y])swap(x,y);
 int d=deep[x]-deep[y];
 for(int i=0;i<=18;i++)
  if((1<<i)&d)x=fa[x][i];
 for(int i=18;i>=0;i--)
  if(fa[x][i]!=fa[y][i]) 
   {x=fa[x][i];y=fa[y][i];}
 if(x==y)return x;
 else return fa[x][0];
}
int dis(int x,int y)
{
 return deep[x]+deep[y]-2*deep[lca(x,y)];
}
void cal(int x,int y,int z)
{
 int p1=lca(x,y),p2=lca(x,z),p3=lca(y,z),t;
 if(p1==p2)t=p3;
 else if(p2==p3)t=p1;
 else t=p2;
 int ans;
 ans=dis(x,t)+dis(y,t)+dis(z,t);
 printf("%d %d\n",t,ans);
}
int main()
{
 scanf("%d%d",&n,&q);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  insert(u,v);
 }
 dfs(1);
 for(int i=1;i<=q;i++)
 {
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  cal(x,y,z);
 }
 return 0;
}
