// Problem : P4151 [WC2011]最大XOR和路径
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4151
// Memory Limit : 500 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
struct edge
{
 int v,next;
 long long w;
}e[200005];
int head[50005],vis[50005],cnt;
long long res[50005],p[65];
void add(long long x)
{
 for(int i=63;i>=0;i--)
  if((x>>i)&1)
  {
   if(!p[i])
   {
    p[i]=x;
    return;
   }
   else x^=p[i];
  }
}
long long query(long long x)
{
 for(int i=63;i>=0;i--)
  if((x^p[i])>x)x^=p[i];
 return x;
}
void addedge(int u,int v,long long w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,long long w)
{
 vis[u]=1;
 res[u]=w;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(vis[v])add(w^e[i].w^res[v]);
  else dfs(v,w^e[i].w);
 }
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  long long w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 dfs(1,0);
 cout<<query(res[n])<<endl;
 return 0;
}