#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[1000005];
int n,m,s,t,cnt=1;
int head[1005],dep[1005],vis[1005],cur[1005],pr[1005],tot[1005],ans;
vector<int> e1[1005];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool bfs()
{
 queue<int> q;
 memset(dep,INF,sizeof(dep));
 memset(vis,0,sizeof(vis));
 memcpy(cur,head,sizeof(head));
 dep[s]=0;
 vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int p=q.front();
  q.pop();
  vis[p]=0;
  for(int i=head[p];i;i=e[i].next)
   if(dep[e[i].v]>dep[p]+1&&e[i].w)
   {
    dep[e[i].v]=dep[p]+1;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 if(dep[t]==INF)return 0;
 return 1;
}
int dfs(int p,int w)
{
 if(p==t)return w;
 int used=0;
 for(int i=cur[p];i;i=e[i].next)
 {
  cur[p]=i;
  if(dep[e[i].v]==dep[p]+1&&e[i].w)
  {
   int flow=dfs(e[i].v,min(w-used,e[i].w));
   if(flow)
   {
    used+=flow;
    e[i].w-=flow;
    e[i^1].w+=flow;
    if(used==w)break;
   }
  }
 }
 return used;
}
int f(int x,int y)
{
 return x*m+y+1;
}
void topo()
{
 queue<int> q;
 for(int i=1;i<=n*m;i++)
  if(!tot[i])q.push(i);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  if(pr[u]>=0)
   addedge(s,u,pr[u]),addedge(u,s,0),ans+=pr[u];
  else
   addedge(u,t,-pr[u]),addedge(t,u,0);
  for(auto v:e1[u])
  {
   addedge(v,u,INF),addedge(u,v,0);
   tot[v]--;
   if(!tot[v])q.push(v);
  }
 }
}
int main()
{
 cin>>n>>m;
 s=m*n+1,t=m*n+2;
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
  {
   int u=f(i,j),v=f(i,j+1),w;
   cin>>pr[u]>>w;
   if(j!=m-1)
    e1[v].push_back(u),tot[u]++;
   while(w--)
   {
    int x,y;
    cin>>x>>y;
    v=f(x,y);
    e1[u].push_back(v),tot[v]++;
   }
  }
 topo();
 while(bfs())
  ans-=dfs(s,INF);
 cout<<ans<<endl;
 return 0;
}