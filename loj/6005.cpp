#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int a[505],f[505];
struct edge
{
 int v,w,next;
}e[100005];
int s,t,cnt=1;
int head[1005],dep[1005],vis[1005],cur[1005];
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
int main()
{
 int n,len=0,ans=0;
 cin>>n;
 
 //problem 1
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  f[i]=1;
  for(int j=1;j<i;j++)
   if(a[i]>=a[j])f[i]=max(f[i],f[j]+1);
  len=max(len,f[i]);
 }
 cout<<len<<endl;
 
 //problem 2
 s=2*n+1,t=2*n+2,cnt=1,ans=0;
 for(int i=1;i<=n;i++)
  addedge(i,i+n,1),addedge(i+n,i,0);
 for(int i=1;i<=n;i++)
 {
  if(f[i]==1)addedge(s,i,1),addedge(i,s,0);
  if(f[i]==len)addedge(i+n,t,1),addedge(t,i+n,0);
  for(int j=i+1;j<=n;j++)
   if(f[j]==f[i]+1&&a[j]>=a[i])addedge(i+n,j,1),addedge(j,i+n,0);
 }
 while(bfs())
  ans+=dfs(s,INF);
 cout<<ans<<endl;
 
 //problem 3
 if(n==1)
 {
  cout<<1<<endl;
  return 0;
 }
 memset(head,0,sizeof(head));
 cnt=1,ans=0;
 for(int i=1;i<=n;i++)
  if(i!=1&&i!=n)addedge(i,i+n,1),addedge(i+n,i,0);
  else addedge(i,i+n,INF),addedge(i+n,i,0);
 for(int i=1;i<=n;i++)
 {
  if(f[i]==1)
  {
   if(i!=1)addedge(s,i,1),addedge(i,s,0);
   else addedge(s,i,INF),addedge(i,s,0);
  }
  if(f[i]==len)
  {
   if(i!=n)addedge(i+n,t,1),addedge(t,i+n,0);
   else addedge(i+n,t,INF),addedge(t,i+n,0);
  }
  for(int j=i+1;j<=n;j++)
   if(f[j]==f[i]+1&&a[j]>=a[i])addedge(i+n,j,1),addedge(j,i+n,0);
 }
 while(bfs())
  ans+=dfs(s,INF);
 cout<<ans<<endl;
 
 return 0;
}