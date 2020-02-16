#include <cstring>
#include <iostream>
#include <algorithm>
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
int head[2005],dis[2005],vis[2005];
int n,m,s,t,cnt=1,minc,maxw;
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
   if(e[i].w&&dis[u]+e[i].c<dis[e[i].v])
   {
    dis[e[i].v]=dis[u]+e[i].c;
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
 cin>>n>>m;
 s=n+1,t=n;
 for(int i=1;i<=n;i++)
  addedge(i,i+n,1,0),addedge(i+n,i,0,0);
 for(int i=1;i<=m;i++)
 {
  int u,v,c;
  cin>>u>>v>>c;
  addedge(u+n,v,1,c);
  addedge(v,u+n,0,-c);
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
  minc+=minw*dis[t];
 }
 cout<<maxw<<' '<<minc<<endl;
 return 0;
}