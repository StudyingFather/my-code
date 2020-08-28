// Problem : P3749 [六省联考2017]寿司餐厅
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3749
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[1000005];
int head[10005],cur[10005],dep[10005],vis[10005],cnt=1,s,t;
int a[105],d[105][105],id[105][105],cntp;
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
 ios::sync_with_stdio(false);
 int n,m,ans=0;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
   cin>>d[i][j],id[i][j]=++cntp;
 s=cntp+1000+1,t=s+1;
 for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
  {
   int u=id[i][j];
   if(i==j)
   {
    d[i][j]-=a[i];
    addedge(u,cntp+a[i],INF),addedge(cntp+a[i],u,0);
   }
   int v1=id[i+1][j],v2=id[i][j-1];
   if(d[i][j]>0)
    addedge(s,u,d[i][j]),addedge(u,s,0),ans+=d[i][j];
   else
    addedge(u,t,-d[i][j]),addedge(t,u,0);
   if(i==j)continue;
   addedge(u,v1,INF),addedge(v1,u,0);
   addedge(u,v2,INF),addedge(v2,u,0);
  }
 for(int i=1;i<=1000;i++)
  addedge(cntp+i,t,m*i*i),addedge(t,cntp+i,0);
 while(bfs())
  ans-=dfs(s,INF);
 cout<<ans<<endl;
 return 0;
}