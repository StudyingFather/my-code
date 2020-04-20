#include <iostream>
#include <vector>
#define INF 1e9
struct edge
{
 int v,w,next;
}e[400005];
using namespace std;
vector<int> son[200005],g[200005][2],mx[200005];
int head[200005],cnt;
int f[200005][2],l[200005],ans;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs1(int u,int fa)
{
 f[u][0]=0,f[u][1]=-INF;
 int max1=-INF,max2=-INF;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  l[v]=e[i].w;
  son[u].push_back(v);
  dfs1(v,u);
  int tmp=max(f[v][0],f[v][1]+l[v]);
  f[u][0]+=tmp;
  int res=f[v][0]+l[v]-tmp;
  if(res>max1)max2=max1,max1=res;
  else if(res>max2)max2=res;
 }
 f[u][1]=f[u][0]+max1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  int tmp=max(f[v][0],f[v][1]+l[v]);
  int res=f[v][0]+l[v]-tmp;
  g[u][0].push_back(f[u][0]-tmp);
  if(res==max1)
  {
   g[u][1].push_back(g[u][0].back()+max2);
   mx[u].push_back(max2);
  }
  else
  {
   g[u][1].push_back(g[u][0].back()+max1);
   mx[u].push_back(max1);
  }
 }
}
void dfs2(int u,int fa)
{
 int siz=son[u].size();
 for(int i=0;i<siz;i++)
 {
  int v=son[u][i];
  f[u][0]=g[u][0][i],f[u][1]=g[u][1][i];
  if(fa)
  {
   int tmp=max(f[fa][0],f[fa][1]+l[u]);
   f[u][0]+=tmp;
   f[u][1]=f[u][0]+max(mx[u][i],f[fa][0]+l[u]-tmp);
  }
  ans=max(ans,f[v][0]+max(f[u][0],f[u][1]+l[v]));
  dfs2(v,u);
 }
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 dfs1(1,0);
 dfs2(1,0);
 cout<<ans<<endl;
 return 0;
}