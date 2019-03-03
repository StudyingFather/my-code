#include <iostream>
#define MOD 1000000007
using namespace std;
struct edge
{
 int v,next;
}e[200005];
long long vis[100005],col[100005],head[100005],f[100005][3],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int cur)
{
 vis[cur]=1;
 if(col[cur])f[cur][col[cur]]=1;
 else f[cur][1]=f[cur][2]=f[cur][3]=1;
 for(int i=head[cur];i;i=e[i].next)
  if(!vis[e[i].v])
  {
   dfs(e[i].v);
   f[cur][1]=f[cur][1]*((f[e[i].v][2]+f[e[i].v][3])%MOD)%MOD;
   f[cur][2]=f[cur][2]*((f[e[i].v][1]+f[e[i].v][3])%MOD)%MOD;
   f[cur][3]=f[cur][3]*((f[e[i].v][2]+f[e[i].v][1])%MOD)%MOD;
  }
}
int main()
{
 int n,k;
 cin>>n>>k;
 for(int i=1;i<n;i++)
 {
  int x,y;
  cin>>x>>y;
  addedge(x,y);
  addedge(y,x);
 }
 for(int i=1;i<=k;i++)
 {
  int x,y;
  cin>>x>>y;
  col[x]=y;
 }
 dfs(1);
 cout<<(f[1][1]+f[1][2]+f[1][3])%MOD<<endl;
 return 0;
}
