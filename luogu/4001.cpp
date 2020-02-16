#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 int x,y;
 bool operator<(const node&a)const
 {
  return y>a.y;
 }
};
struct edge
{
 int v,w,next;
}e[10000005];
int a[1005][1005],b[1005][1005],c[1005][1005];
int n,m,s,t,cnt;
int dis[2000005],head[2000005],vis[2000005];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int f(int x,int y,int z)
{
 return z*(m-1)*n+(m-1)*(x-1)+y;
}
int dijkstra()
{
 priority_queue<node> q;
 memset(dis,63,sizeof(dis));
 dis[s]=0;
 q.push({s,0});
 while(!q.empty())
 {
  int u=q.top().x;
  q.pop();
  if(vis[u])continue;
  vis[u]=1;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(dis[v]>dis[u]+e[i].w)
   {
    dis[v]=dis[u]+e[i].w;
    if(!vis[v])q.push({v,dis[v]});
   }
  }
 }
 return dis[t];
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 s=2*n*m+1,t=2*n*m+2;
 for(int i=1;i<=n;i++)
  for(int j=1;j<m;j++)
   cin>>a[i][j];
 for(int i=1;i<n;i++)
  for(int j=1;j<=m;j++)
   cin>>b[i][j];
 for(int i=1;i<n;i++)
  for(int j=1;j<m;j++)
   cin>>c[i][j];
 for(int j=1;j<m;j++)
 {
  int v=f(1,j,0);
  addedge(s,v,a[1][j]);
  addedge(v,s,a[1][j]);
 }
 for(int i=2;i<n;i++)
  for(int j=1;j<m;j++)
  {
   int u=f(i-1,j,1),v=f(i,j,0);
   addedge(u,v,a[i][j]);
   addedge(v,u,a[i][j]);
  }
 for(int j=1;j<m;j++)
 {
  int u=f(n-1,j,1);
  addedge(u,t,a[n][j]);
  addedge(t,u,a[n][j]);
 }
 for(int i=1;i<n;i++)
 {
  int u=f(i,1,1);
  addedge(t,u,b[i][1]);
  addedge(u,t,b[i][1]);
 }
 for(int i=1;i<n;i++)
  for(int j=2;j<m;j++)
  {
   int u=f(i,j-1,0),v=f(i,j,1);
   addedge(u,v,b[i][j]);
   addedge(v,u,b[i][j]);
  }
 for(int i=1;i<n;i++)
 {
  int u=f(i,m-1,0);
  addedge(s,u,b[i][m]);
  addedge(u,s,b[i][m]);
 }
 for(int i=1;i<n;i++)
  for(int j=1;j<m;j++)
  {
   int u=f(i,j,0),v=f(i,j,1);
   addedge(u,v,c[i][j]);
   addedge(v,u,c[i][j]);
  }
 cout<<dijkstra()<<endl;
 return 0;
}