#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next;
}e[200005];
struct node
{
 int v,e;
}p[2005];
int head[2005],dis[2005],vis[2005],id[55][55],a[55][55];
int n,m,s,t,cnt=1,minc;
void addedge(int u,int v,int w,int c)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].c=c;
 e[cnt].next=head[u];
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
int main()
{
 int tot=0;
 cin>>m>>n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m+i-1;j++)
   cin>>a[i][j],id[i][j]=++tot;
 
 //problem 1
 s=2*tot+1,t=2*tot+2;
 memset(head,0,sizeof(head));
 cnt=1,minc=0;
 for(int i=1;i<=m;i++)
  addedge(s,i,1,0),addedge(i,s,0,0);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m+i-1;j++)
  {
   int u=id[i][j],v1=id[i+1][j],v2=id[i+1][j+1];
   addedge(u,u+tot,1,a[i][j]),addedge(u+tot,u,0,-a[i][j]);
   if(i!=n)addedge(u+tot,v1,1,0),addedge(v1,u+tot,0,0);
   if(i!=n)addedge(u+tot,v2,1,0),addedge(v2,u+tot,0,0);
  }
 for(int i=1;i<=m+n-1;i++)
 {
  int u=id[n][i];
  addedge(u+tot,t,1,0),addedge(t,u+tot,0,0);
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
  minc+=minw*dis[t];
 }
 cout<<-minc<<endl;
 
 //problem 2
 s=2*tot+1,t=2*tot+2;
 memset(head,0,sizeof(head));
 cnt=1,minc=0;
 for(int i=1;i<=m;i++)
  addedge(s,i,1,0),addedge(i,s,0,0);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m+i-1;j++)
  {
   int u=id[i][j],v1=id[i+1][j],v2=id[i+1][j+1];
   addedge(u,u+tot,INF,a[i][j]),addedge(u+tot,u,0,-a[i][j]);
   if(i!=n)addedge(u+tot,v1,1,0),addedge(v1,u+tot,0,0);
   if(i!=n)addedge(u+tot,v2,1,0),addedge(v2,u+tot,0,0);
  }
 for(int i=1;i<=m+n-1;i++)
 {
  int u=id[n][i];
  addedge(u+tot,t,INF,0),addedge(t,u+tot,0,0);
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
  minc+=minw*dis[t];
 }
 cout<<-minc<<endl;
 
 //problem 3
 s=2*tot+1,t=2*tot+2;
 memset(head,0,sizeof(head));
 cnt=1,minc=0;
 for(int i=1;i<=m;i++)
  addedge(s,i,1,0),addedge(i,s,0,0);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m+i-1;j++)
  {
   int u=id[i][j],v1=id[i+1][j],v2=id[i+1][j+1];
   addedge(u,u+tot,INF,a[i][j]),addedge(u+tot,u,0,-a[i][j]);
   if(i!=n)addedge(u+tot,v1,INF,0),addedge(v1,u+tot,0,0);
   if(i!=n)addedge(u+tot,v2,INF,0),addedge(v2,u+tot,0,0);
  }
 for(int i=1;i<=m+n-1;i++)
 {
  int u=id[n][i];
  addedge(u+tot,t,INF,0),addedge(t,u+tot,0,0);
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
  minc+=minw*dis[t];
 }
 cout<<-minc<<endl;
 
 return 0;
}