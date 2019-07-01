#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,t,k,next;
}e[2000005];
int head[1000005],dist1[1000005],dist2[1000005],vis[1000005],cnt;
queue<int> que;
void addedge(int u,int v,int t,int k)
{
 e[++cnt].v=v;
 e[cnt].t=t;
 e[cnt].k=k;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m,p,q;
 cin>>n>>m>>p>>q;
 for(int i=1;i<=m;i++)
 {
  int x,y,t,k;
  cin>>x>>y>>t>>k;
  addedge(x,y,t,k);
  addedge(y,x,t,k);
 }
 memset(dist1,INF,sizeof(dist1));
 memset(dist2,INF,sizeof(dist2));
 que.push(p);
 dist1[p]=dist2[p]=0;
 vis[p]=1;
 while(!que.empty())
 {
  int cur=que.front();
  que.pop();
  vis[cur]=0;
  for(int i=head[cur];i;i=e[i].next)
   if(dist2[cur]<e[i].k)
    if(dist1[cur]+e[i].t<dist1[e[i].v]||(dist1[cur]+e[i].t==dist1[e[i].v]&&dist2[cur]+1<dist2[e[i].v]))
    {
     dist2[e[i].v]=dist2[cur]+1;
     dist1[e[i].v]=dist1[cur]+e[i].t;
     if(!vis[cur])
     {
      que.push(e[i].v);
      vis[e[i].v]=1;
     }
    }
 }
 if(dist1[q]==INF)cout<<"bao 0"<<endl;
 else cout<<dist1[q]<<endl;
 return 0;
}