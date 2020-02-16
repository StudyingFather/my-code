#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define INF 4557430888798830399ll
using namespace std;
struct edge
{
 int v,next;
 long long w,c;
}e[500005];
struct node
{
 int v,e;
}p[50005];
struct seg
{
 int x1,y1,x2,y2;
 long long len;
}a[505];
int head[50005],vis[50005],b[50005];
long long dis[50005];
int n,k,s,t,cnt=1;
long long minc;
void addedge(int u,int v,long long w,long long c)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].c=c;
 e[cnt].next=head[u];
 head[u]=cnt;
}
long long calc(int x1,int y1,int x2,int y2)
{
 return sqrt(1ll*(x2-x1)*(x2-x1)+1ll*(y2-y1)*(y2-y1));
}
bool spfa()
{
 queue<int> q;
 memset(dis,63,sizeof(dis));
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
 return dis[t]!=INF;
}
int main()
{
 cin>>n>>k;
 s=2*n+1,t=2*n+2;
 int tot=0;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
  a[i].len=calc(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
  if(a[i].x1>a[i].x2)swap(a[i].x1,a[i].x2);
  a[i].x1*=2,a[i].x2*=2;
  if(a[i].x1==a[i].x2)a[i].x2++;
  else a[i].x1++;
  b[++tot]=a[i].x1;
  b[++tot]=a[i].x2;
 }
 sort(b+1,b+tot+1);
 int len=unique(b+1,b+tot+1)-b-1;
 for(int i=1;i<len;i++)
 {
  addedge(i,i+1,k,0);
  addedge(i+1,i,0,0);
 }
 addedge(s,1,k,0),addedge(1,s,0,0);
 addedge(len,t,k,0),addedge(t,len,0,0);
 for(int i=1;i<=n;i++)
 {
  int u=lower_bound(b+1,b+len+1,a[i].x1)-b;
  int v=lower_bound(b+1,b+len+1,a[i].x2)-b;
  addedge(u,v,1,a[i].len);
  addedge(v,u,0,-a[i].len);
 }
 while(spfa())
 {
  long long minw=INF;
  for(int i=t;i!=s;i=p[i].v)
   minw=min(minw,e[p[i].e].w);
  for(int i=t;i!=s;i=p[i].v)
  {
   e[p[i].e].w-=minw;
   e[p[i].e^1].w+=minw;
  }
  minc+=minw*dis[t];
 }
 cout<<-minc<<endl;
 return 0;
}