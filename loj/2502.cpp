#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;
struct edge
{
 int v,nxt;
}e[200005],ansi_e[200005];
int head[10005],cnt;
int vis[10005],dist[10005],que[10005],he=0,tail=1,del[10005];
inline void addedge(int x,int y)
{
 e[++cnt].v=y;
 e[cnt].nxt=head[x];
 head[x]=cnt;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  if(x==y)continue;
  addedge(y,x);
 }
 int s,t;
 scanf("%d%d",&s,&t);
 que[he]=t,vis[t]=1;
 while(he!=tail)
 {
  for(int i=head[que[he]];i;i=e[i].nxt)
   if(!vis[e[i].v])
   {
    vis[e[i].v]=1;
    que[tail++]=e[i].v;
   }
  he++;
 }
 int delnum=0;
 for(int i=1;i<=n;i++)
 {
  for(int j=head[i];j;j=e[j].nxt)
   if(vis[e[j].v]&&(!vis[i]))del[++delnum]=e[j].v;
 }
 for(int i=1;i<=delnum;i++)
  vis[del[i]]=0;
 que[he=0]=t,dist[t]=0,tail=1;
 while(he!=tail)
 {
  for(int i=head[que[he]];i;i=e[i].nxt)
   if(vis[e[i].v]&&dist[e[i].v]==0)que[tail++]=e[i].v,dist[e[i].v]=dist[que[he]]+1;
  he++;
 }
 if(dist[s]==0)printf("-1\n");
 else printf("%d\n",dist[s]);
 return 0;
}