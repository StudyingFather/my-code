// Problem : D. Flights for Regular Customers
// Contest : Codeforces - Codeforces Round #319 (Div. 1)
// URL : https://codeforces.com/contest/576/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <bitset>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1ll<<62
using namespace std;
typedef bitset<256> bi;
int n,m;
struct edge
{
 int u,v,w;
 bool operator<(const edge&a)const
 {
  return w<a.w;
 }
};
struct mat
{
 bi a[155];
}f;
bi operator*(bi a,mat b)
{
 bi ans;
 for(int i=1;i<=n;i++)
  ans[i]=(a&b.a[i]).any();
 return ans;
}
mat operator*(mat a,mat b)
{
 mat ans;
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   if(a.a[k][i])ans.a[k]|=b.a[i];
 return ans;
}
vector<edge> e;
bi v;
long long ans=INF,dis[155];
bi fpow(mat x,int y,bi z)
{
 while(y)
 {
  if(y&1)z=z*x;
  x=x*x;
  y>>=1;
 }
 return z;
}
int main()
{
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  e.push_back({u,v,w});
 }
 sort(e.begin(),e.end());
 int lt=0;
 v[1]=1;
 for(auto ed:e)
 {
  int d=ed.w-lt;
  v=fpow(f,d,v);
  f.a[ed.v][ed.u]=1;
  lt=ed.w;
  queue<int> q;
  for(int i=1;i<=n;i++)
  {
   if(v[i])
    dis[i]=0,q.push(i);
   else dis[i]=INF;
  }
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(int v=1;v<=n;v++)
    if(f.a[v][u]&&dis[v]==INF)
     dis[v]=dis[u]+1,q.push(v);
  }
  ans=min(ans,lt+dis[n]);
 }
 if(ans!=INF)cout<<ans<<endl;
 else cout<<"Impossible"<<endl;
 return 0;
}