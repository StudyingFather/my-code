#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int a[1005],f[1005][1005],vis[1005][1005];
vector<int> e[1005];
queue<pair<int,int> > q;
int main()
{
 int n,m,c,ans=0;
 cin>>n>>m>>c;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
 }
 q.push({0,1});
 memset(f,-1,sizeof(f));
 f[0][1]=0;
 while(!q.empty())
 {
  int d=q.front().first,u=q.front().second;
  q.pop();
  if(d>1000)break;
  for(auto v:e[u])
  {
   if(f[d+1][v]<f[d][u]+a[v])
   {
    f[d+1][v]=f[d][u]+a[v];
    if(!vis[d+1][v])
    {
     vis[d+1][v]=1;
     q.push({d+1,v});
    }
   }
  }
  if(u==1)ans=max(ans,f[d][u]-c*d*d);
 }
 cout<<ans<<endl;
 return 0;
}