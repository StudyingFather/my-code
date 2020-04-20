#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int id,v;
}p[505];
vector<int> e[505];
int n,m;
struct graph
{
 struct edge
 {
  int v,w,c,next;
 }e[1000005];
 struct node
 {
  int v,e;
 }p[2005];
 int head[2005],dis[2005],vis[2005];
 int s,t,cnt,minc;
 void init(int S,int T)
 {
  memset(head,0,sizeof(head));
  cnt=1,minc=0;
  s=S,t=T;
 }
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
 int mcmf()
 {
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
  return -minc;
 }
}g;
bool cmp(const node&a,const node&b)
{
 return a.v<b.v;
}
bool check(int x)
{
 int maxv=p[x].v;
 int s=2*m+1,t=2*m+2;
 g.init(s,t);
 g.addedge(s,s+2,n,0),g.addedge(s+2,s,0,0);
 g.addedge(t+2,t,n,0),g.addedge(t,t+2,0,0);
 for(int i=1;i<=m;i++)
 {
  int u=p[i].id;
  g.addedge(s+2,u,INF,0),g.addedge(u,s+2,0,0);
  g.addedge(u+m,t+2,INF,0),g.addedge(t+2,u+m,0,0);
  if(p[i].v<=maxv)
   g.addedge(u,u+m,1,1),g.addedge(u+m,u,0,-1);
  g.addedge(u,u+m,INF,0),g.addedge(u+m,u,0,0);
  for(auto v:e[u])
   g.addedge(u+m,v,INF,0),g.addedge(v,u+m,0,0);
 }
 return g.mcmf()>=x;
}
int main()
{
 cin>>n>>m;
 n++;
 for(int i=1;i<=m;i++)
 {
  int k;
  cin>>p[i].v>>k;
  p[i].id=i;
  while(k--)
  {
   int x;
   cin>>x;
   e[i].push_back(x);
  }
 }
 sort(p+1,p+m+1,cmp);
 int l=1,r=m,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid))ans=mid,l=mid+1;
  else r=mid-1;
 }
 if(ans==m)cout<<"AK"<<endl;
 else cout<<p[ans+1].v<<endl;
 return 0;
}