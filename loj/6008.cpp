#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next;
}e[400005];
struct node
{
 int v,e;
}p[4005];
int head[4005],vis[4005],dis[4005];
int n,s,t,cnt=1;
long long minc;
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
 q.push(s);
 dis[s]=0;
 vis[s]=1;
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
 int P,M,F,N,S;
 cin>>n>>P>>M>>F>>N>>S;
 s=2*n+1,t=2*n+2;
 for(int i=1;i<=n;i++)
 {
  int r;
  cin>>r;
  addedge(s,i+n,r,0);
  addedge(i+n,s,0,0);
  addedge(i,t,r,0);
  addedge(t,i,0,0);
 }
 for(int i=1;i<=n;i++)
 {
  int u=i,v=i+n;
  if(i<n)
   addedge(v,v+1,INF,0),addedge(v+1,v,0,0);
  if(i+M<=n)
   addedge(v,u+M,INF,F),addedge(u+M,v,0,-F);
  if(i+N<=n)
   addedge(v,u+N,INF,S),addedge(u+N,v,0,-S);
  addedge(s,u,INF,P),addedge(u,s,0,-P);
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
 cout<<minc<<endl;
 return 0;
}