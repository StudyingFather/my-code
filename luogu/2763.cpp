/*
 Name: luogu P2763
 Author: StudyingFather
 Date: 2019/08/01 21:08
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
int head[2005],vis[2005],cur[2005],dep[2005],s,t,cnt=1,k,n;
queue<int> res[25];
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
int main()
{
 scanf("%d%d",&k,&n);
 int ans=0;
 s=n+k+1,t=n+k+2;
 for(int i=1;i<=k;i++)
 {
  int x;
  scanf("%d",&x);
  addedge(n+i,t,x);
  addedge(t,n+i,0);
  ans+=x;
 }
 for(int i=1;i<=n;i++)
 {
  int p;
  scanf("%d",&p);
  addedge(s,i,1);
  addedge(i,s,0);
  while(p--)
  {
   int x;
   scanf("%d",&x);
   addedge(i,n+x,1);
   addedge(n+x,i,0);
  }
 }
 while(bfs())
  ans-=dfs(s,INF);
 if(ans)
 {
  puts("No Solution!");
  return 0;
 }
 for(int i=1;i<=n;i++)
  for(int j=head[i];j;j=e[j].next)
   if(!e[j].w)res[e[j].v-n].push(i);
 for(int i=1;i<=k;i++)
 {
  printf("%d: ",i);
  while(!res[i].empty())
  {
   printf("%d ",res[i].front());
   res[i].pop();
  }
  puts("");
 }
 return 0;
}