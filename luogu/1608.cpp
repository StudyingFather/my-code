#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int ma[2005][2005],dist[2005],num[2005],vis[2005],n,m;
queue<int> q;
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 memset(ma,INF,sizeof(ma));
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  ma[u][v]=min(ma[u][v],w);
 }
 memset(dist,INF,sizeof(dist));
 dist[1]=0,num[1]=1,vis[1]=1,q.push(1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int v=1;v<=n;v++)
   if(ma[u][v]==INF)continue;
   else if(dist[v]>dist[u]+ma[u][v])
   {
    dist[v]=dist[u]+ma[u][v];
    num[v]=num[u];
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
   else if(dist[v]==dist[u]+ma[u][v])
   {
    num[v]+=num[u];
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
  if(u!=n)num[u]=0;
 }
 if(!num[n])puts("No answer");
 else printf("%d %d\n",dist[n],num[n]);
 return 0;
}