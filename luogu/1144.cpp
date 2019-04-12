#include <cstdio>
#include <queue>
#define MOD 100003
using namespace std;
struct edge
{
 int v,next;
}e[4000005];
int head[1000005],cnt,dep[1000005],vis[1000005],f[1000005];
queue<int> q;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
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
 dep[1]=0;
 vis[1]=1;
 f[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int p=q.front();
  q.pop();
  for(int i=head[p];i;i=e[i].next)
  {
   int x=e[i].v;
   if(!vis[x])
   {
    vis[x]=1;
    dep[x]=dep[p]+1;
    q.push(x);
   }
   if(dep[x]==dep[p]+1)
   {
    f[x]+=f[p];
    f[x]%=MOD;
   }
  }
 }
 for(int i=1;i<=n;i++)
  printf("%d\n",f[i]);
 return 0;
}