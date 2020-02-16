#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#define INF 0x3f3f3f3f
#define UINF -1077952577
using namespace std;
map<string,int> m1;
map<int,string> m2;
struct edge
{
 int v,w,c,next;
}e[80005];
struct node
{
 int v,e;
}p[205];
int head[205],dis[205],vis[205];
int n,m,s,t,cnt=1,maxw,minf;
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
void dfs1(int u)
{
 vis[u]=1;
 cout<<m2[u-n]<<endl;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v<=n&&!e[i].w)
  {
   dfs1(e[i].v+n);
   break;
  }
}
void dfs2(int u)
{
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v<=n&&!vis[e[i].v+n]&&!e[i].w)
   dfs2(e[i].v+n);
 cout<<m2[u-n]<<endl;
}
int main()
{
 bool flag=false;
 cin>>n>>m;
 s=1,t=2*n;
 for(int i=1;i<=n;i++)
 {
  string str;
  cin>>str;
  m1[str]=i;
  m2[i]=str;
  if(i==1||i==n)
  {
   addedge(i,i+n,2,0);
   addedge(i+n,i,0,0);
  }
  else
  {
   addedge(i,i+n,1,0);
   addedge(i+n,i,0,0);
  }
 }
 for(int i=1;i<=m;i++)
 {
  string s,t;
  cin>>s>>t;
  int u=m1[s],v=m1[t];
  if(u==1&&v==n)flag=true;
  addedge(u+n,v,1,1);
  addedge(v,u+n,0,-1);
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
  minf+=minw*dis[t];
 }
 if(maxw!=2&&!flag)cout<<"No Solution!"<<endl;
 else if(maxw!=2&&flag)
 {
  cout<<2<<endl;
  cout<<m2[1]<<endl<<m2[n]<<endl<<m2[1]<<endl;
 }
 else
 {
  cout<<-minf<<endl;
  dfs1(n+1);
  dfs2(n+1);
 }
 return 0;
}