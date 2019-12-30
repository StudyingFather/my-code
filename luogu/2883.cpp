#include <iostream>
#include <queue>
using namespace std;
struct graph
{
 struct edge
 {
  int v,next;
 }e[50005];
 int head[50005],t[50005],cnt,n;
 long long w[50005];
 void addedge(int u,int v)
 {
  e[++cnt].v=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  t[v]++;
 }
 void topo()
 {
  queue<int> q;
  for(int i=1;i<=n;i++)
   if(!t[i])
   {
    q.push(i);
    w[i]=1;
   }
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(int i=head[u];i;i=e[i].next)
   {
    int v=e[i].v;
    w[v]+=w[u];
    t[v]--;
    if(!t[v])q.push(v);
   }
  }
 }
}e1,e2;
int main()
{
 int n,m;
 cin>>n>>m;
 e1.n=e2.n=n;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e1.addedge(u,v);
  e2.addedge(v,u);
 }
 e1.topo();
 e2.topo();
 long long ans=0;
 for(int u=1;u<=n;u++)
  for(int i=e1.head[u];i;i=e1.e[i].next)
  {
   int v=e1.e[i].v;
   ans=max(ans,e1.w[u]*e2.w[v]);
  }
 cout<<ans<<endl;
 return 0;
}