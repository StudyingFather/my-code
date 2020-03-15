#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
 int v,w,next;
}e[2500005];
struct node
{
 int u,w;
 bool operator<(const node&a)const
 {
  return w>a.w;
 }
};
int n,s,t;
int head[500005],dis[500005],vis[500005],cnt;
int id[505][505];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int dijkstra()
{
 priority_queue<node> q;
 memset(dis,63,sizeof(dis));
 dis[s]=0;
 q.push({s,0});
 while(!q.empty())
 {
  int u=q.top().u;
  q.pop();
  if(vis[u])continue;
  vis[u]=1;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(dis[v]>dis[u]+e[i].w)
   {
    dis[v]=dis[u]+e[i].w;
    q.push({v,dis[v]});
   }
  }
 }
 return dis[t];
}
int main()
{
 cin>>n;
 n++;
 s=n*n+1,t=n*n+2;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   id[i][j]=(i-1)*n+j;
 for(int i=1;i<=n;i++)
  for(int j=1;j<n;j++)
  {
   int x;
   cin>>x;
   if(i==1)addedge(s,id[i][j],x);
   else if(i==n)addedge(id[i-1][j],t,x);
   else addedge(id[i-1][j],id[i][j],x);
  }
 for(int i=1;i<n;i++)
  for(int j=1;j<=n;j++)
  {
   int x;
   cin>>x;
   if(j==1)addedge(id[i][j],t,x);
   else if(j==n)addedge(s,id[i][j-1],x);
   else addedge(id[i][j],id[i][j-1],x);
  }
 for(int i=1;i<=n;i++)
  for(int j=1;j<n;j++)
  {
   int x;
   cin>>x;
   if(i==1)addedge(id[i][j],s,x);
   else if(i==n)addedge(t,id[i-1][j],x);
   else addedge(id[i][j],id[i-1][j],x);
  }
 for(int i=1;i<n;i++)
  for(int j=1;j<=n;j++)
  {
   int x;
   cin>>x;
   if(j==1)addedge(t,id[i][j],x);
   else if(j==n)addedge(id[i][j-1],s,x);
   else addedge(id[i][j-1],id[i][j],x);
  }
 cout<<dijkstra()<<endl;
 return 0;
}