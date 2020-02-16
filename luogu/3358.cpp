#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,c,next;
}e[200005];
struct node
{
 int v,e;
}p[2005];
struct seg
{
 int l,r;
}a[505];
int head[2005],dis[2005],vis[2005],b[2005];
int n,k,s,t,cnt=1,minc;
void addedge(int u,int v,int w,int c)
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
 memset(dis,INF,sizeof(dis));
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
  cin>>a[i].l>>a[i].r;
  b[++tot]=a[i].l;
  b[++tot]=a[i].r;
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
  int u=lower_bound(b+1,b+len+1,a[i].l)-b;
  int v=lower_bound(b+1,b+len+1,a[i].r)-b;
  addedge(u,v,1,a[i].r-a[i].l);
  addedge(v,u,0,a[i].l-a[i].r);
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
  minc+=minw*dis[t];
 }
 cout<<-minc<<endl;
 return 0;
}