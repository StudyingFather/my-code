#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
int n,m,cnt,vis[10005],head[10005],x,y,ans;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool dfs(int cur,int col)
{
 vis[cur]=col;
 if(col==0)x++;
 else y++;
 bool flag=true;
 for(int i=head[cur];i;i=e[i].next)
  if(vis[e[i].v]==-1)
  {
   flag=dfs(e[i].v,!col);
   if(!flag)return false;
  }
  else if(vis[e[i].v]==vis[cur])return false;
 return true;
}
int main()
{
 memset(vis,-1,sizeof(vis));
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=n;i++)
  if(vis[i]==-1)
  {
   x=0,y=0;
   if(!dfs(i,0))
   {
    puts("Impossible");
    return 0;
   }
   ans+=min(x,y);
  }
 printf("%d\n",ans);
 return 0;
}