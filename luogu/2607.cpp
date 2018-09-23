#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int v,next;
}e[2000005];
int head[1000005],tot,U,V,E,vis[1000005];
long long val[1000005],f[1000005][2];
void add(int u,int v)
{
 e[tot].v=v;
 e[tot].next=head[u];
 head[u]=tot++;
}
void dfs(int u,int from)
{
 vis[u]=1;
 for(int i=head[u];~i;i=e[i].next)
 {
  if(e[i].v==from)continue;
  int v=e[i].v;
  if(vis[v])
  {
   U=u,V=v,E=i;
   continue;
  }
  dfs(v,u);
 }
}
void dp(int u,int from)
{
 f[u][0]=0,f[u][1]=val[u];
 for(int i=head[u];~i;i=e[i].next)
 {
  if(i==E||(i^1)==E||(i^1)==from)continue;
  int v=e[i].v;
  dp(v,i);
  f[u][0]+=max(f[v][0],f[v][1]);
  f[u][1]+=f[v][0];
 }
}
int main()
{
 ios::sync_with_stdio(false);
 int t,x;
 cin>>t;
 memset(head,-1,sizeof(head));
 for(int i=1;i<=t;++i)
 {
  cin>>val[i]>>x;
  add(i,x);
  add(x,i);
 }
 long long ans=0;
 for(int i=1;i<=t;i++)
  if(!vis[i])
  {
   dfs(i,-1);
   dp(U,-1);
   long long temp=f[U][0];
   dp(V,-1);
   ans+=max(temp,f[V][0]);
  }
 cout<<ans;
 return 0;
}
