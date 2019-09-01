/*
 Name: luogu P2472
 Author: StudyingFather
 Date: 2019/08/14 16:15
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
}e[400005];
char ma[25][25],str[25];
int head[805],cur[805],dist[805],s,t,cnt=1;
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
 memset(dist,INF,sizeof(dist));
 dist[s]=0;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w&&dist[e[i].v]>dist[u]+1)
   {
    dist[e[i].v]=dist[u]+1;
    q.push(e[i].v);
   }
 }
 return dist[t]!=INF;
}
int dfs(int u,int flow)
{
 if(u==t)return flow;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  cur[u]=i;
  int v=e[i].v;
  if(e[i].w&&dist[v]==dist[u]+1)
  {
   int w=dfs(v,min(flow-used,e[i].w));
   if(w)
   {
    used+=w;
    e[i].w-=w;
    e[i^1].w+=w;
    if(used==flow)break;
   }
  }
 }
 return used;
}
int calc(int x1,int y1,int x2,int y2)
{
 return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
 int r,c,d;
 scanf("%d%d%d",&r,&c,&d);
 s=2*r*c+1,t=2*r*c+2;
 for(int i=1;i<=r;i++)
  scanf("%s",ma[i]+1);
 for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++)
   if(ma[i][j]!='0')
   {
    int numu=(i-1)*c+j;
    addedge(numu,r*c+numu,ma[i][j]-'0');
    addedge(r*c+numu,numu,0);
    for(int k=1;k<=i;k++)
     for(int l=1;k!=i?l<=c:l<j;l++)
      if(ma[k][l]!='0'&&calc(i,j,k,l)<=d*d)
      {
       int numv=(k-1)*c+l;
       addedge(r*c+numu,numv,INF);
       addedge(numv,r*c+numu,0);
       addedge(r*c+numv,numu,INF);
       addedge(numu,r*c+numv,0);
      }
    if(i<=d||r+1-i<=d||j<=d||c+1-j<=d)
    {
     addedge(r*c+numu,t,INF);
     addedge(t,r*c+numu,0);
    }
   }
 int ans=0;
 for(int i=1;i<=r;i++)
 {
  scanf("%s",str+1);
  for(int j=1;j<=c;j++)
   if(str[j]=='L')
   {
    int num=(i-1)*c+j;
    addedge(s,num,1);
    addedge(num,s,0);
    ans++;
   }
 }
 while(bfs())
  ans-=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}