// Problem : P1099 树网的核
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1099
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct edge
{
 int v,w,next;
}e[605];
int head[305],dis[305],vis[305],cnt,ans=2e9;
int root,root2;
vector<int> l,path;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs1(int u,int fa)
{
 if(dis[u]>dis[root])root=u;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=fa)
  {
   dis[v]=dis[u]+e[i].w;
   dfs1(v,u);
  }
 }
}
void dfs2(int u,int fa)
{
 path.push_back(u);
 if(dis[u]>dis[root2])
 {
  root2=u;
  l=path;
 }
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=fa)
  {
   dis[v]=dis[u]+e[i].w;
   dfs2(v,u);
  }
 }
 path.pop_back();
}
int dfs(int u,int d)
{
 vis[u]=1;
 int maxd=d;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(!vis[v])
   maxd=max(dfs(v,d+e[i].w),maxd);
 }
 return maxd;
}
int main()
{
 int n,s;
 cin>>n>>s;
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 dfs1(1,1);
 memset(dis,0,sizeof(dis));
 dfs2(root,root);
 int siz=l.size();
 for(int i=0;i<siz;i++)
  for(int j=i;j<siz;j++)
  {
   int res=0;
   memset(vis,0,sizeof(vis));
   int u=l[i],v=l[j];
   for(int k=i;k<=j;k++)
    vis[l[k]]=1;
   if(dis[v]-dis[u]<=s)
   {
    for(int k=i;k<=j;k++)
     res=max(res,dfs(l[k],0));
    ans=min(ans,res); 
   }
  }
 cout<<ans<<endl;
 return 0;
}