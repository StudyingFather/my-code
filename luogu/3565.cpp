#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> e[5005];
long long ans,f[5005][2];
int n,dep[5005];
void dfs(int u,int fa,int d)
{
 dep[d]++;
 for(auto v:e[u])
  if(v!=fa)
   dfs(v,u,d+1);
}
int main()
{
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 for(int i=1;i<=n;i++)
 {
  memset(f,0,sizeof(f));
  for(auto v:e[i])
  {
   memset(dep,0,sizeof(dep));
   dfs(v,i,1);
   for(int j=1;j<=n;j++)
   {
    ans+=f[j][1]*dep[j];
    f[j][1]+=f[j][0]*dep[j];
    f[j][0]+=dep[j];
   }
  }
 }
 cout<<ans<<endl;
 return 0;
}