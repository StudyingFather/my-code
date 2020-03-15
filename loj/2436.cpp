#include <iostream>
#include <queue>
using namespace std;
struct edge
{
 int v,w,next;
}e[300005];
int head[100005],vis[100005],tot[100005],cnt;
long long ans,dist[100005];
queue<int> q;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 ios::sync_with_stdio(false);
 int n,k;
 cin>>n>>k;
 for(int i=1;i<=k;i++)
 {
  int x,a,b;
  cin>>x>>a>>b;
  if(x==1)addedge(a,b,0),addedge(b,a,0);
  else if(x==2)
  {
   if(a==b)
   {
   	cout<<-1<<endl;
   	return 0;
   }
   else addedge(a,b,1);
  }
  else if(x==3)addedge(b,a,0);
  else if(x==4)
  {
   if(a==b)
   {
   	cout<<-1<<endl;
   	return 0;
   }
   else addedge(b,a,1);
  }
  else if(x==5)addedge(a,b,0);
 }
 for(int i=n;i>=1;i--)
  addedge(0,i,1);
 vis[0]=1;
 q.push(0);
 while(!q.empty())
 {
  int cur=q.front();
  q.pop();
  vis[cur]=0;
  for(int i=head[cur];i;i=e[i].next)
   if(dist[cur]+e[i].w>dist[e[i].v])
   {
   	dist[e[i].v]=dist[cur]+e[i].w;
   	if(!vis[e[i].v])
   	{
   	 vis[e[i].v]=1;
   	 q.push(e[i].v);
   	 tot[e[i].v]++;
   	 if(tot[e[i].v]>=n)
   	 {
   	  cout<<-1<<endl;
   	  return 0;
   	 }
   	}
   }
 }
 for(int i=1;i<=n;i++)
  ans+=dist[i];
 cout<<ans<<endl;
 return 0;
}