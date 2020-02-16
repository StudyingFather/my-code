#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int x,y,z;
}e1[50005];
struct edge
{
 int v,w,next;
}e2[20005];
int f[10005],head[10005],vis[10005],fa[10005][25],dep[10005],dist[10005][25];
int cnt;
bool cmp(const node&a,const node&b)
{
 return a.z>b.z;
}
int find(int x)
{
 return f[x]==x?x:f[x]=find(f[x]);
}
void unionn(int x,int y)
{
 f[x]=y;
}
void addedge(int u,int v,int w)
{
 e2[++cnt].v=v;
 e2[cnt].w=w;
 e2[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int cur)
{
 vis[cur]=1;
 for(int i=head[cur];i;i=e2[i].next)
 {
  if(vis[e2[i].v])continue;
  dep[e2[i].v]=dep[cur]+1;
  fa[e2[i].v][0]=cur;
  dist[e2[i].v][0]=e2[i].w;
  dfs(e2[i].v);
 }
 return;
}
int query(int x,int y)
{
 int ans=INF;
 if(dep[x]>dep[y])swap(x,y);
 for(int i=15;i>=0;i--)
  if(dep[y]>=dep[x]+(1<<i))
  {
   ans=min(ans,dist[y][i]);
   y=fa[y][i];
  }
 if(x==y)return ans;
 for(int i=15;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   ans=min(ans,dist[x][i]);
   x=fa[x][i];
   ans=min(ans,dist[y][i]);
   y=fa[y][i];
  }
 ans=min(ans,min(dist[x][0],dist[y][0]));
 return ans;
}
int main()
{
 int n,m,q;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&e1[i].x,&e1[i].y,&e1[i].z);
 for(int i=1;i<=n;i++)
  f[i]=i;
 sort(e1+1,e1+m+1,cmp);
 for(int i=1;i<=m;i++)
  if(find(e1[i].x)!=find(e1[i].y))
  {
   unionn(find(e1[i].x),find(e1[i].y));
   addedge(e1[i].x,e1[i].y,e1[i].z);
   addedge(e1[i].y,e1[i].x,e1[i].z);
  }
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   dep[i]=1;
   dfs(i);
   fa[i][0]=i;
   dist[i][0]=INF;
  }
 for(int i=1;i<=15;i++)
  for(int j=1;j<=n;j++)
  {
   fa[j][i]=fa[fa[j][i-1]][i-1];
   dist[j][i]=min(dist[j][i-1],dist[fa[j][i-1]][i-1]);
  }
 scanf("%d",&q);
 for(int i=1;i<=q;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  if(find(x)!=find(y))puts("-1");
  else printf("%d\n",query(x,y));
 }
 return 0;
}