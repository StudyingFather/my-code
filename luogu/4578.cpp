#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct edge
{
 int v,w,next;
}e[3000005];
int head[3005],tot[3005],dis[3005],vis[3005],cnt,n,m,k;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa(int s)
{
 queue<int> q;
 memset(dis,63,sizeof(dis));
 memset(vis,0,sizeof(vis));
 dis[s]=0,vis[s]=1;
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
    {
     vis[v]=1,tot[v]++;
     if(tot[v]==n+m)return false;
     q.push(v);
    }
   }
  }
 }
 return true;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  memset(head,0,sizeof(head));
  memset(tot,0,sizeof(tot));
  cnt=0;
  cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
   int x,y,c;
   cin>>x>>y>>c;
   addedge(x,y+n,c);
   addedge(y+n,x,-c);
  }
  for(int i=1;i<=n+m;i++)
   addedge(0,i,0);
  if(spfa(0))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
 }
 return 0;
}