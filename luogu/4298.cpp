/*
 Name: luogu P4298
 Author: StudyingFather
 Date: 2019/08/01 19:41
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[2000005];
int f[105][105],head[205],vis[205],cur[205],dep[205],s,t,cnt=1,n,m;
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
 memcpy(cur,head,sizeof(cur));
 memset(dep,INF,sizeof(dep));
 dep[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dep[e[i].v]>dep[u]+1)
   {
    dep[e[i].v]=dep[u]+1;
    if(!vis[e[i].v])
    {
     q.push(e[i].v);
     vis[e[i].v]=1;
    }
   }
 }
 return dep[t]!=INF;
}
int dfs(int u,int w)
{
 if(u==t)return w;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  cur[u]=i;
  if(dep[e[i].v]==dep[u]+1&&e[i].w)
  {
   int flow=dfs(e[i].v,min(w,e[i].w));
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
int res[205];
void find(int u)
{
 if(!res[u]&&u<=n)return;
 if(res[u]&&u>n)return;
 if(u<=n)
 {
  res[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w)find(e[i].v);
 }
 else
 {
  res[u]=1;
  for(int i=head[u];i;i=e[i].next)
   if(!e[i^1].w)find(e[i].v);
 }
}
int main()
{
 //Initiation start
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  f[u][v]=1;
 } 
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=f[i][j]||(f[i][k]&&f[k][j]);
 //Initiation end

 //Part 1 start
 s=2*n+1,t=2*n+2;
 for(int i=1;i<=n;i++)
 {
  addedge(s,i,1);
  addedge(i,s,0);
  addedge(i+n,t,1);
  addedge(t,i+n,0);
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(i!=j&&f[i][j])
   {
    addedge(i,j+n,1);
    addedge(j+n,i,0);
   }
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans=n-ans);
 //Part 1 end

 //Part 2 start
 for(int i=1;i<=n;i++)
  res[i]=1;
 for(int i=1;i<=n;i++)
  if(e[4*i-2].w)find(i);
 for(int i=1;i<=n;i++)
  printf("%d",!(res[i]|res[i+n]));
 puts("");
 //Part 2 end
 
 //Part 3 start
 for(int i=1;i<=n;i++)
 {
  memset(head,0,sizeof(head));
  cnt=1;
  int cntp=0;
  for(int j=1;j<=n;j++)
   if(i!=j&&(!f[i][j])&&(!f[j][i]))
   {
    addedge(s,j,1);
    addedge(j,s,0);
    addedge(j+n,t,1);
    addedge(t,j+n,0);
    cntp++;
   }
  for(int j=1;j<=n;j++)
   for(int k=1;k<=n;k++)
    if(j!=k&&i!=j&&f[j][k])
    {
     addedge(j,k+n,1);
     addedge(k+n,j,0);
    }
  while(bfs())
   cntp-=dfs(s,INF);
  printf("%d",ans-1==cntp);
 }
 //Part 3 end
 
 return 0;
}