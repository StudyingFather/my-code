#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
priority_queue<int,vector<int>,greater<int> > q;
int vis[100005],head[100005],cnte,res[100005],cntp;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 q.push(1);
 vis[1]=1;
 while(!q.empty())
 {
  int p=q.top();
  q.pop();
  res[++cntp]=p;
  for(int i=head[p];i;i=e[i].next)
   if(!vis[e[i].v])
   {
	q.push(e[i].v);
	vis[e[i].v]=1;
   }
 }
 for(int i=1;i<=n;i++)
  printf("%d ",res[i]);
 return 0;
}