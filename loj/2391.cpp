#include <cstring>
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int p[2000005],vis[1000005],col[1000005];
vector<int> e[1000005];
int fa[2000005],nxt[1000005];
int cnt;
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool dfs(int u,int c)
{
 col[u]=c;
 for(auto v:e[u])
  if(col[v]==col[u])return false;
  else if(col[v]==-1)
  {
   if(!dfs(v,c^1))return false;
  }
 return true;
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int l,r;
  cin>>l>>r;
  p[l]=p[r]=i;
 }
 for(int i=1;i<=n+1;i++)
  fa[i]=i,nxt[i]=i;
 for(int i=1;i<=2*n;i++)
  if(!vis[p[i]])
   vis[p[i]]=++cnt;
  else
  {
   int id=vis[p[i]],t;
   fa[id]=find(id+1);
   for(int j=fa[id];j<=cnt;j=t)
   {
    e[id].push_back(j);
    e[j].push_back(id);
    t=find(nxt[j]+1);
    nxt[j]=cnt;
   }
  }
 memset(col,-1,sizeof(col));
 int ans=1;
 for(int i=1;i<=n;i++)
  if(col[i]==-1)
  {
   if(dfs(i,0))ans=ans*2%MOD;
   else ans=0;
  }
 cout<<ans<<endl;
 return 0;
}