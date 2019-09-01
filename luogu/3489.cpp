/*
 Name: luogu P3489
 Author: StudyingFather
 Date: 2019/08/22 10:30
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
 int v,w,p,next;
}e[6005];
struct node
{
 int u,p;
};
int head[205],dist[205][40005],vis[205][40005],a[205],n,m,p,k,cnt;
queue<node> q;
void addedge(int u,int v,int w,int p)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].p=p;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 scanf("%d%d%d%d",&n,&m,&p,&k);
 for(int i=1;i<=k;i++)
 {
  int w,q;
  scanf("%d%d",&w,&q);
  for(int j=1;j<=q;j++)
  {
   int x;
   scanf("%d",&x);
   a[w]|=(1<<x);
  }
 }
 for(int i=1;i<=m;i++)
 {
  int u,v,t,s,tmp=0;
  scanf("%d%d%d%d",&u,&v,&t,&s);
  for(int j=1;j<=s;j++)
  {
   int x;
   scanf("%d",&x);
   tmp|=(1<<x);
  }
  addedge(u,v,t,tmp);
  addedge(v,u,t,tmp);
 }
 memset(dist,INF,sizeof(dist));
 dist[1][a[1]]=0,vis[1][a[1]]=1;
 q.push({1,a[1]});
 while(!q.empty())
 {
  int u=q.front().u,p=q.front().p;
  q.pop();
  vis[u][p]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v,w=e[i].w,np=e[i].p;
   if((np&p)==np&&dist[v][p|a[e[i].v]]>dist[u][p]+w)
   {
    dist[v][p|a[e[i].v]]=dist[u][p]+w;
    if(!vis[v][p|a[e[i].v]])
    {
     vis[v][p|a[e[i].v]]=1;
     q.push({v,p|a[e[i].v]});
    }
   }
  }
 }
 int ans=INF;
 for(int i=0;i<=(1<<(p+1));i++)
  ans=min(ans,dist[n][i]);
 printf("%d\n",ans==INF?-1:ans);
 return 0;
}