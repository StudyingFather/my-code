#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 2000000000
using namespace std;
struct edge
{
 int v,w,f,next;
}e[50005];
struct node
{
 int v,e;
}po[55];
int n,s,t,maxw,maxf,cnt=1;
int p[25][25],q[25][25],vis[55],head[55],dist[55];
void addedge(int u,int v,int w,int f)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].f=f;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa()
{
 queue<int> que;
 for(int i=1;i<=2*n+2;i++)
  dist[i]=-INF;
 que.push(s);
 dist[s]=0;
 vis[s]=1;
 while(!que.empty())
 {
  int cur=que.front();
  que.pop();
  vis[cur]=0;
  for(int i=head[cur];i;i=e[i].next)
   if(e[i].w&&dist[cur]+e[i].f>dist[e[i].v])
   {
    dist[e[i].v]=dist[cur]+e[i].f;
    po[e[i].v].v=cur;
    po[e[i].v].e=i;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     que.push(e[i].v);
    }
   }
 }
 return dist[t]!=-INF;
}
int main()
{
 scanf("%d",&n);
 s=2*n+1,t=2*n+2;
 for(int i=1;i<=n;i++)
 {
  addedge(s,i,1,0);
  addedge(i,s,0,0);
 }
 for(int i=1;i<=n;i++)
 {
  addedge(i+n,t,1,0);
  addedge(t,i+n,0,0);
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&p[i][j]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&q[i][j]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   addedge(i,j+n,1,p[i][j]*q[j][i]);
   addedge(j+n,i,0,-p[i][j]*q[j][i]);
  }
 while(spfa())
 {
  int minw=INF;
  for(int i=t;i!=s;i=po[i].v)
   minw=min(minw,e[po[i].e].w);
  for(int i=t;i!=s;i=po[i].v)
  {
   e[po[i].e].w-=minw;
   e[po[i].e^1].w+=minw;
  }
  maxw+=minw;
  maxf+=minw*dist[t];
 }
 printf("%d\n",maxf);
 return 0;
}