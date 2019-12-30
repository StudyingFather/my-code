#include <cstdio>
struct edge
{
 int v,w,next;
}e[400005];
int fa[100005],head[100005],dis[100005],cnt;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
void dfs(int u,int fa,int w)
{
 dis[u]=w;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=fa)
   dfs(e[i].v,u,w^e[i].w);
}
int main()
{
 int n,m,q;
 scanf("%d%d%d",&n,&m,&q);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  int fu=find(u),fv=find(v);
  if(fu!=fv)
  {
   unionn(fu,fv);
   addedge(u,v,w);
   addedge(v,u,w);
  }
 }
 dfs(1,0,0);
 while(q--)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  printf("%d\n",dis[u]^dis[v]);
 }
 return 0;
}