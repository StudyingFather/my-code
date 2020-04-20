#include <cstdio>
#include <vector>
using namespace std;
vector<int> e[1000005],f[1000005];
int fa[1000005],len[1000005],son[1000005];
int ans[1000005];
void dfs1(int u,int f)
{
 fa[u]=f;
 for(auto v:e[u])
  if(v!=f)
  {
   dfs1(v,u);
   if(len[v]>=len[son[u]])
    son[u]=v,len[u]=len[v]+1;
  }
}
void dfs2(int u)
{
 if(son[u])
 {
  dfs2(son[u]);
  swap(f[u],f[son[u]]);
  f[u].push_back(1);
  ans[u]=ans[son[u]];
  if(f[u][ans[u]]==1)ans[u]=len[u];
  for(auto v:e[u])
  {
   if(v==fa[u]||v==son[u])continue;
   dfs2(v);
   for(int i=len[v];i>=0;i--)
   {
    int tmp=i+len[u]-len[v]-1;
    f[u][tmp]+=f[v][i];
    if(f[u][tmp]>f[u][ans[u]]||(f[u][tmp]==f[u][ans[u]]&&tmp>ans[u]))
     ans[u]=tmp;
   }
  }
 }
 else
 {
  f[u].push_back(1);
  ans[u]=0;
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs1(1,0);
 dfs2(1);
 for(int i=1;i<=n;i++)
  printf("%d\n",len[i]-ans[i]);
 return 0;
}