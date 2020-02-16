#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next,dir;
}e[500005];
struct node
{
 int v,e;
}p[2505];
int head[2505],dis[2505],vis[2505],a[55][55],id[55][55];
int n,k,s,t,cnt=1,maxw,tot;
void addedge(int u,int v,int w,int c,int dir=-1)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].c=c;
 e[cnt].next=head[u];
 e[cnt].dir=dir;
 head[u]=cnt;
}
bool spfa()
{
 queue<int> q;
 memset(dis,INF,sizeof(dis));
 dis[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dis[u]-e[i].c<dis[e[i].v])
   {
    dis[e[i].v]=dis[u]-e[i].c;
    p[e[i].v].v=u;
    p[e[i].v].e=i;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 return dis[t]!=INF;
}
void dfs(int id,int u)
{
 vis[u]=1,vis[u+tot]=1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==t)return;
  if(!vis[v]&&e[i^1].w)
  {
   if(e[i].dir!=-1)cout<<id<<' '<<e[i].dir<<endl;
   e[i].w++,e[i^1].w--;
   dfs(id,v+tot);
   break;
  }
 }
}
int main()
{
 int n,P,Q;
 cin>>n>>P>>Q;
 s=2*P*Q+1,t=2*P*Q+2;
 for(int i=1;i<=Q;i++)
  for(int j=1;j<=P;j++)
  {
   cin>>a[i][j];
   id[i][j]=++tot;
   if(a[i][j]!=1)
    addedge(tot,tot+P*Q,INF,0),addedge(tot+P*Q,tot,0,0);
   if(a[i][j]==2)
    addedge(tot,tot+P*Q,1,1),addedge(tot+P*Q,tot,0,-1);
  }
 addedge(s,1,n,0),addedge(1,s,0,0);
 addedge(2*P*Q,t,n,0),addedge(t,2*P*Q,0,0);
 for(int i=1;i<=Q;i++)
  for(int j=1;j<=P;j++)
  {
   int u=id[i][j],v1=id[i][j+1],v2=id[i+1][j];
   if(v1)
    addedge(u+P*Q,v1,INF,0,1),addedge(v1,u+P*Q,0,0,1);
   if(v2)
    addedge(u+P*Q,v2,INF,0,0),addedge(v2,u+P*Q,0,0,0);
  }
 while(spfa())
 {
  int minw=INF;
  for(int i=t;i!=s;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=t;i!=s;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  maxw+=minw;
 }
 for(int i=1;i<=maxw;i++)
 {
  memset(vis,0,sizeof(vis));
  dfs(i,tot+1);
 }
 return 0;
}