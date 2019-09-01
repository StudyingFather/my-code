/*
 Name: loj 6226
 Author: StudyingFather
 Date: 2019/08/24 17:38
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
const int dx[]={-1,-2,-2,-1};
const int dy[]={-2,-1,1,2};
int ma[205][205],head[40005],vis[40005],cur[40005],dep[40005],s,t,cnt=1,m,n;
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
 scanf("%d%d",&n,&m);
 s=n*n+1,t=n*n+2;
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  ma[x][y]=1;
 }
 for(int x=1;x<=n;x++)
  for(int y=1;y<=n;y++)
  {
   if(ma[x][y])continue;
   int num=(x-1)*n+y;
   if((x+y)&1)
   {
    addedge(s,num,1);
    addedge(num,s,0);
   }
   else
   {
    addedge(num,t,1);
    addedge(t,num,0);
   }
   for(int i=0;i<4;i++)
   {
    int nx=x+dx[i],ny=y+dy[i];
    int num1=(nx-1)*n+ny;
    if(!ma[nx][ny]&&nx>0&&nx<=n&&ny>0&&ny<=n)
    {
     if((nx+ny)&1)
     {
      addedge(num1,num,1);
      addedge(num,num1,0);
     }
     else
     {
      addedge(num,num1,1);
      addedge(num1,num,0);
     }
    }
   }
  }
 int ans=n*n-m;
 while(bfs())
  ans-=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}