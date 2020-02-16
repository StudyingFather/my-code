#include <iostream>
using namespace std;
struct edge
{
 int v,w,next;
}e[2000005];
int head[1000005],siz[1000005],n,cnt;
long long ans;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa,int w)
{
 siz[u]=1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=fa)
  {
   dfs(v,u,e[i].w);
   siz[u]+=siz[v];
  }
 }
 ans+=1ll*w*abs(2*siz[u]-n);
}
int main()
{
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 dfs(1,1,0);
 cout<<ans<<endl;
 return 0;
}