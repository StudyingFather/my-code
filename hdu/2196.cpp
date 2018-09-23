#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct edge
{
 int t,next,w;
}e[20005];
int cnt,head[10005],idx[10005];
long long d[10005][3];
void insert(int u,int v,int w)
{
 e[++cnt].next=head[u];
 e[cnt].w=w;
 e[cnt].t=v;
 head[u]=cnt;
}
void dfs1(int u,int fa)
{
 long long mx0=0,mx1=0;
 for(int i=head[u];~i;i=e[i].next)
 {
  int v=e[i].t;
  if(v==fa)continue;
  dfs1(v,u);
  if(mx0<=d[v][0]+e[i].w)
  {
   mx1=mx0;
   mx0=d[v][0]+e[i].w;
   idx[u]=v;
  }
  else if(mx1<d[v][0]+e[i].w)mx1=d[v][0]+e[i].w;
  else if(mx1<d[v][1]+e[i].w)mx1=d[v][1]+e[i].w;
 }
 d[u][0]=mx0;
 d[u][1]=mx1;
}
void dfs2(int u,int fa)
{
 for(int i=head[u];~i;i=e[i].next)
 {
  int v=e[i].t;
  if(v==fa)continue;
  if(idx[u]==v)d[v][2]=max(d[u][1]+e[i].w,d[u][2]+e[i].w);
  else d[v][2]=max(d[u][0]+e[i].w,d[u][2]+e[i].w);
  dfs2(v,u);
 }
}
int main()
{
 int n;
 while(cin>>n)
 {
  memset(d,0,sizeof(d));
  memset(head,-1,sizeof(head));
  cnt=0;
  for(int u=2;u<=n;u++)
  {
   int v,w;
   cin>>v>>w;
   insert(u,v,w);
   insert(v,u,w);
  }
  dfs1(1,1);
  dfs2(1,1);
  for(int u=1;u<=n;u++)
   cout<<max(d[u][0],d[u][2])<<endl;
 }
 return 0;
}
