/*
 Name: luogu P1462
 Author: StudyingFather
 Date: 2019/09/16 20:10
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[100005];
int n,m,b,head[10005],c[10005],vis[10005],cnt;
long long dist[10005];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool check(int maxc)
{
 memset(dist,INF,sizeof(dist));
 queue<int> q;
 dist[1]=0,vis[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(c[v]<=maxc&&dist[v]>dist[u]+e[i].w)
   {
    dist[v]=dist[u]+e[i].w;
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
  }
 }
 return dist[n]<b;
}
int main()
{
 scanf("%d%d%d",&n,&m,&b);
 for(int i=1;i<=n;i++)
  scanf("%d",&c[i]);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,w);
 }
 int l=0,r=1e9;
 while(l<r)
 {
  int mid=(l+r)>>1;
  if(check(mid))r=mid;
  else l=mid+1;
 }
 if(check(l))printf("%d\n",l);
 else puts("AFK");
 return 0;
}