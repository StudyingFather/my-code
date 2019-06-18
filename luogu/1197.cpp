#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[400005];
int vis[400005],res[400005],head[400005],used[400005],fa[400005],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
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
int main()
{
 int n,m,k;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  addedge(x+1,y+1);
  addedge(y+1,x+1);
 }
 scanf("%d",&k);
 for(int i=1;i<=k;i++)
 {
  scanf("%d",&used[i]);
  used[i]++;
  vis[used[i]]=1;
 }
 int tot=n-k;
 for(int i=1;i<=n;i++)
  for(int j=head[i];j;j=e[j].next)
   if((!vis[i])&&(!vis[e[j].v])&&find(i)!=find(e[j].v))
   {
    unionn(find(i),find(e[j].v));
    tot--;
   }
 res[k+1]=tot;
 for(int i=k;i;i--)
 {
  tot++;
  vis[used[i]]=0;
  for(int j=head[used[i]];j;j=e[j].next)
   if((!vis[e[j].v])&&find(used[i])!=find(e[j].v))
   {
    tot--;
    unionn(find(used[i]),find(e[j].v));
   }
  res[i]=tot;
 }
 for(int i=1;i<=k+1;i++)
  printf("%d\n",res[i]);
 return 0;
}