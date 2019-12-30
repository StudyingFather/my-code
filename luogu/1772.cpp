#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
 int v,w,next;
}e[1005];
int head[25],t[25][105],cnt;
long long f[105],res[105][105];
int n,m,k,l;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int use[105],vis[105],dis[105];
bool check(int u,int x,int y)
{
 bool flag=false;
 for(int i=x;i<=y;i++)
  flag|=t[u][i];
 return !flag;
}
int spfa(int x,int y)
{
 queue<int> q;
 memset(use,0,sizeof(use));
 memset(dis,63,sizeof(dis));
 for(int i=1;i<=m;i++)
  if(check(i,x,y))use[i]=1;
 dis[1]=0,vis[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(use[v]&&dis[v]>dis[u]+e[i].w)
   {
    dis[v]=dis[u]+e[i].w;
    if(!vis[v])
    {
     vis[v]=1;
     q.push(v);
    }
   }
  }
 }
 return dis[m];
}
int main()
{
 cin>>n>>m>>k>>l;
 for(int i=1;i<=l;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 int d;
 cin>>d;
 for(int i=1;i<=d;i++)
 {
  int p,a,b;
  cin>>p>>a>>b;
  for(int j=a;j<=b;j++)
   t[p][j]=1;
 }
 for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
   res[i][j]=spfa(i,j);
 f[0]=0;
 for(int i=1;i<=n;i++)
 {
  f[i]=res[1][i]*i;
  for(int j=0;j<i;j++)
   f[i]=min(f[i],f[j]+res[j+1][i]*(i-j)+k);
 }
 cout<<f[n]<<endl;
 return 0;
}