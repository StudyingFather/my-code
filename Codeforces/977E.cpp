#include <cstdio>
#include <vector>
using namespace std;
struct edge
{
 int v,next;
}e[400005];
int t[200005],head[200005],cnt,vis[200005];
vector<int> path;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u)
{
 vis[u]=1;
 path.push_back(u);
 for(int i=head[u];i;i=e[i].next)
  if(!vis[e[i].v])dfs(e[i].v);
 return;
}
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  t[u]++,t[v]++;
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   path.clear();
   dfs(i);
   int maxn=path.size(),flag=1;
   for(int i=0;i<maxn;i++)
    if(t[path[i]]!=2)
    {
     flag=0;
     break;
    }
   ans+=flag;
  }
 printf("%d\n",ans);
 return 0;
}