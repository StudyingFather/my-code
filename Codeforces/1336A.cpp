#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dep[200005],siz[200005],f[200005];
vector<int> e[200005];
bool cmp(int a,int b)
{
 return a>b;
}
void dfs(int u,int fa)
{
 siz[u]=1;
 dep[u]=dep[fa]+1;
 for(auto v:e[u])
  if(v!=fa)
  {
   dfs(v,u);
   siz[u]+=siz[v];
  }
 f[u]=siz[u]-dep[u];
}
int main()
{
 ios::sync_with_stdio(false);
 int n,k;
 long long ans=0;
 cin>>n>>k;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs(1,1);
 sort(f+1,f+n+1,cmp);
 for(int i=1;i<=n-k;i++)
  ans+=f[i];
 cout<<ans<<endl;
 return 0;
}