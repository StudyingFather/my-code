#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#define INF 1e12
#define eqs 1e-8
using namespace std;
struct edge
{
 int v,next,w;
 double c;
}e[50005];
struct node
{
 int v,e;
}p[205];
int head[205],vis[205],a[105][105],b[105][105];
double dis[205],minc;
int n,s,t,cnt=1;
void addedge(int u,int v,int w,double c)
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
 for(int i=1;i<=2*n+2;i++)
  dis[i]=INF;
 dis[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dis[u]-e[i].c<dis[e[i].v])
   {
    dis[e[i].v]=dis[u]-e[i].c;
    p[e[i].v].v=u;
    p[e[i].v].e=i;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 return dis[t]<INF;
}
bool check(double x)
{
 s=2*n+1,t=2*n+2;
 minc=0,cnt=1;
 memset(head,0,sizeof(head));
 for(int i=1;i<=n;i++)
 {
  addedge(s,i,1,0),addedge(i,s,0,0);
  addedge(i+n,t,1,0),addedge(t,i+n,0,0);
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   double c=a[i][j]-x*b[i][j];
   addedge(i,j+n,1,c),addedge(j+n,i,0,-c);
  }
 while(spfa())
 {
  int minw=INF;
  for(int i=t;i!=s;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=t;i!=s;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  minc-=minw*dis[t];
 }
 return minc>=0;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&b[i][j]);
 double l=0,r=1e8;
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))l=mid;
  else r=mid;
 }
 printf("%.6lf\n",l);
 return 0;
}