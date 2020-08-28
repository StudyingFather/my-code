// Problem: #2887. 「APIO2015」雅加达的摩天楼 Jakarta Skyscrapers
// Contest: LibreOJ
// URL: https://loj.ac/problem/2887
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[18000005];
int head[3100005],id[105][30005],dis[3100005],cnt;
bool vis[3100005];
int n,m;
queue<int> q;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int spfa(int s,int t)
{
 memset(dis,INF,sizeof(dis));
 dis[s]=0;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(dis[v]>dis[u]+e[i].w)
   {
    dis[v]=dis[u]+e[i].w;
    if(!vis[v])
     q.push(v),vis[v]=1;
   }
  }
 }
 return dis[t]!=INF?dis[t]:-1;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 int maxp=sqrt(n/3);
 int s,t;
 for(int i=1;i<=maxp;i++)
  for(int j=0;j<n;j++)
   id[i][j]=i*n+j;
 for(int i=1;i<=maxp;i++)
  for(int j=0;j<n;j++)
  {
   addedge(id[i][j],j,0);
   if(i+j>=n)
    break;
   addedge(id[i][j],id[i][j+i],1);
   addedge(id[i][j+i],id[i][j],1);
  }
 for(int i=0;i<m;i++)
 {
  int b,p;
  cin>>b>>p;
  if(p<=maxp)
   addedge(b,id[p][b],0);
  else
  {
   for(int j=1;b+j*p<n;j++)
    addedge(b,b+j*p,j);
   for(int j=1;b-j*p>=0;j++)
    addedge(b,b-j*p,j);
  }
  if(i==0)s=b;
  if(i==1)t=b;
 }
 for(int i=1;i<=maxp;i++)
  for(int j=0;j<n;j++)
   if(head[id[i][j]])addedge(id[i][j],j,0);
 cout<<spfa(s,t)<<endl;
 return 0;
}