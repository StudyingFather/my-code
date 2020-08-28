// Problem: #2171. 「POI2011 R3 Day2」程序设计竞赛 Programming Contest
// Contest: LibreOJ
// URL: https://loj.ac/problem/2171
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next;
}e[1000005];
struct node
{
 int u,id;
}pre[1005];
int head[1005],cnt=1;
int n,m,r,T,k,s,t,tot[505];
int dis[1005],vis[1005];
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
 memset(pre,0,sizeof(pre));
 dis[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v,c=e[i].c;
   if(e[i].w&&dis[v]>dis[u]+c)
   {
    dis[v]=dis[u]+c;
    pre[v]={u,i};
    if(!vis[v])
    {
     q.push(v);
     vis[v]=1;
    }
   }
  }
 }
 return dis[t]!=INF;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m>>r>>T>>k;
 s=n+m+1,t=n+m+2;
 for(int i=1;i<=k;i++)
 {
  int u,v;
  cin>>u>>v;
  tot[u]++;
  addedge(u,v+n,1,0),addedge(v+n,u,0,0);
 }
 for(int i=1;i<=n;i++)
 {
  tot[i]=min(tot[i],T/r);
  for(int j=1;j<=tot[i];j++)
   addedge(s,i,1,r*j),addedge(i,s,0,-r*j);
 }
 for(int i=1;i<=m;i++)
  addedge(n+i,t,1,0),addedge(t,n+i,0,0);
 int maxf=0,minc=0;
 while(spfa())
 {
  int c=0,f=INF;
  for(int u=t;u!=s;u=pre[u].u)
  {
   c+=e[pre[u].id].c;
   f=min(f,e[pre[u].id].w);
  }
  for(int u=t;u!=s;u=pre[u].u)
   e[pre[u].id].w-=f,e[pre[u].id^1].w+=f;
  maxf+=f,minc+=f*c;
 }
 cout<<maxf<<' '<<minc<<endl;
 for(int u=1;u<=n;u++)
 {
  int cnt=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(!e[i].w&&v!=s)
    cout<<u<<' '<<v-n<<' '<<cnt*r<<endl,cnt++;
  }
 }
 return 0;
}