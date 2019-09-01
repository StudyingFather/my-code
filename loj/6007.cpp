/*
 Name: loj 6007
 Author: StudyingFather
 Date: 2019/08/24 17:37
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[100005];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,s,t,cnt=1,ans;
int head[20005],dep[20005],vis[20005],cur[20005];
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
 cin>>m>>n;
 s=m*n+1,t=m*n+2;
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
  {
   int x,p=(i-1)*n+j;
   cin>>x;
   ans+=x;
   if((i+j)%2)
   {
    addedge(s,p,x);
    addedge(p,s,0);
   }
   else
   {
    addedge(p,t,x);
    addedge(t,p,0);
   }
  }
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
  {
   if((i+j)%2)
   {
    for(int k=0;k<4;k++)
    {
     int x=i+dx[k],y=j+dy[k];
     if(x<=0||y<=0||x>m||y>n)continue;
     addedge((i-1)*n+j,(x-1)*n+y,INF);
     addedge((x-1)*n+y,(i-1)*n+j,0);
    }
   }
  }
 while(bfs())
  ans-=dfs(s,INF);
 cout<<ans<<endl;
 return 0;
}