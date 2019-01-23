#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[32005];
int a[16005],head[16005],f[16005],ans=0xffffffff,cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int cur,int fa)
{
 f[cur]=a[cur];
 for(int i=head[cur];i;i=e[i].next)
  if(fa!=e[i].v)
  {
   dfs(e[i].v,cur);
   f[cur]+=max(0,f[e[i].v]);
  }
 ans=max(ans,f[cur]);
 return;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 dfs(1,0);
 printf("%d\n",ans);
 return 0;
}
