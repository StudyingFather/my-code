#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct edge
{
 int v,next;
}e[1000005];
int vis[1005],path[1005],head[1005],f[1005][1005],t[1005],cnt;
queue<int> q;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n,m,ans=1;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int num;
  scanf("%d",&num);
  memset(vis,0,sizeof(vis));
  for(int j=1;j<=num;j++)
  {
   scanf("%d",&path[j]);
   vis[path[j]]=1;
  }
  for(int j=path[1];j<=path[num];j++)
   if(!vis[j])
   {
    for(int k=1;k<=num;k++)
     if(!f[j][path[k]])
     {
      addedge(j,path[k]);
      f[j][path[k]]=1;
      t[path[k]]++;
     }
   }
 }
 for(int i=1;i<=n;i++)
  if(!t[i])q.push(i),t[i]=-1;
 while(1)
 {
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(int i=head[u];i;i=e[i].next)
    if(f[u][e[i].v])t[e[i].v]--,f[u][e[i].v]=0;
  }
  for(int i=1;i<=n;i++)
   if(!t[i])q.push(i),t[i]=-1;
  if(q.empty())
  {
   printf("%d\n",ans);
   return 0;
  }
  else ans++;
 }
}