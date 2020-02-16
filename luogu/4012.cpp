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
int head[2005],dis[2005],vis[2005];
int A,B,P,Q,s,t,cnt=1,minc;
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
int f(int x,int y)
{
 return (P+1)*x+y+1;
}
int main()
{
 cin>>A>>B>>P>>Q;
 s=(P+1)*(Q+1)+1,t=(P+1)*(Q+1)+2;
 /*
 for(int i=0;i<=Q;i++)
 {
  for(int j=0;j<=P;j++)
   cout<<f(i,j)<<' ';
  cout<<endl;
 }
 */
 for(int i=0;i<=P;i++)
  for(int j=0;j<Q;j++)
  {
   int x,u=f(j,i),v=f(j+1,i);
   cin>>x;
   addedge(u,v,1,x);
   addedge(v,u,0,-x);
   addedge(u,v,INF,0);
   addedge(v,u,0,0);
  }
 for(int i=0;i<=Q;i++)
  for(int j=0;j<P;j++)
  {
   int x,u=f(i,j),v=f(i,j+1);
   cin>>x;
   addedge(u,v,1,x);
   addedge(v,u,0,-x);
   addedge(u,v,INF,0);
   addedge(v,u,0,0);
  }
 for(int i=1;i<=A;i++)
 {
  int k,x,y;
  cin>>k>>x>>y;
  swap(x,y);
  int u=f(x,y);
  addedge(s,u,k,0);
  addedge(u,s,0,0);
 }
 for(int i=1;i<=B;i++)
 {
  int r,x,y;
  cin>>r>>x>>y;
  swap(x,y);
  int u=f(x,y);
  addedge(u,t,r,0);
  addedge(t,u,0,0);
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